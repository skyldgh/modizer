//
//  DetailViewController.h
//  modizer1
//
//  Created by Yohann Magnien on 04/06/10.
//  Copyright __YoyoFR / Yohann Magnien__ 2010. All rights reserved.
//

#import "Queue.h"
#import "DBHelper.h"
#import "HardwareClock.h"
#import "RRSGlowLabel.h"

#import "BButton.h"

#import <AVFoundation/AVFoundation.h>
#import <AudioToolbox/AudioToolbox.h>
//#import <CoreLocation/CoreLocation.h>
//#import <MapKit/MapKit.h>

#import <UIKit/UIKit.h>
#import <OpenGLES/EAGL.h>
#import <OpenGLES/ES1/gl.h>
#import <OpenGLES/ES1/glext.h>

#import "OBSlider.h"

#import "ModizMusicPlayer.h"

#import "AppDelegate_Phone.h"
#import "RootViewControllerLocalBrowser.h"

//#import "OouraFFT.h"

#import "GoogleAppHelper.h"

#import <UIKit/UIKit.h>
#import "TapkuLibrary.h"

#define TOUCH_SCROLL_THRESHOLD 33.0f
#define MIN_DELAY_PREV_ENTRY 5000

struct Resources;

@class OGLView;
@class EAGLContext;
@class CADisplayLink;
@class RootViewControllerLocalBrowser;

class CFont;
class CGLString;

@interface DetailViewControllerIphone : UIViewController <UIPickerViewDataSource, UIPickerViewDelegate,  UIGestureRecognizerDelegate, TKCoverflowViewDelegate,TKCoverflowViewDataSource,UIScrollViewDelegate > { //,CLLocationManagerDelegate, MKReverseGeocoderDelegate> {
//	CLLocationManager *locManager;
    
    
    
    //Options
	IBOutlet UISlider *surDepSld,*surDelSld,*revDepSld,*revDelSld,*bassAmoSld,*bassRanSld,*mastVolSld,*mpPanningSld;
    
	IBOutlet UISegmentedControl *sc_allowPopup;
	IBOutlet UISegmentedControl *segcont_mpSampling;
	IBOutlet UISegmentedControl *segcont_mpMB,*segcont_mpReverb,*segcont_mpSUR,*sc_AOSDKDSFDSP,*sc_AOSDKDSFEmuRatio,*sc_AOSDKSSFDSP,*sc_AOSDKSSFEmuRatio,*sc_AOSDKDSF22KHZ;
    //,*segcont_resumeLaunch
	IBOutlet UISegmentedControl *sc_UADE_Led,*sc_UADE_Norm,*sc_UADE_PostFX,*sc_UADE_Pan,*sc_UADE_Head,*sc_UADE_Gain;
	IBOutlet UISegmentedControl *sc_SEXYPSF_Reverb,*sc_SEXYPSF_Interpol;
	IBOutlet UISegmentedControl *sc_AOSDK_Reverb,*sc_AOSDK_Interpol,*sc_SID_Optim,*sc_SID_LibVersion,*sc_SID_Filter;
   	IBOutlet UISegmentedControl *sc_ADPLUG_opltype;
	IBOutlet UISlider *sld_UADEpan,*sld_UADEgain;
	///////////////////////
    
    
    //CoverFlow
    TKCoverflowView *coverflow; 
    UILabel *lblMainCoverflow,*lblSecCoverflow,*lblCurrentSongCFlow,*lblTimeFCflow;
    UIButton *btnPlayCFlow,*btnPauseCFlow,*btnBackCFlow,*btnNextCFlow,*btnPrevCFlow,*btnNextSubCFlow,*btnPrevSubCFlow;
    //
	
	UIView *waitingView;
	
	ModizMusicPlayer *mplayer;
	
	NSString *ratingImg[6];
	

	int oglViewFullscreen,oglViewFullscreenChanged;
	int orientationHV;
	IBOutlet UIPickerView *pvSubSongSel,*pvArcSel;
	IBOutlet OGLView* m_oglView;
	EAGLContext* m_oglContext;
	st::HardwareClock m_clock;
	CADisplayLink* m_displayLink;
	
	UIView *mInWasView;
	BOOL mInWasViewHidden;


	IBOutlet RRSGlowLabel *labelModuleName;

	/*
    //Link to LocalBrowser viewcontroller
	IBOutlet RootViewControllerLocalBrowser *rootViewControllerIphone;
     */
	
    //Subsongs and Archive entries picker
	IBOutlet UILabel *pvSubSongLabel,*pvArcLabel;
	IBOutlet UIButton *pvSubSongValidate,*pvArcValidate,*btnChangeTime;
    IBOutlet BButton *btnShowArcList,*btnShowSubSong;

	
	IBOutlet UILabel *labelTime,*labelModuleLength;
	IBOutlet UILabel *labelSeeking;
	IBOutlet UILabel *labelModuleSize,*labelNumChannels,*labelModuleType,*playlistPos,*labelLibName;
	IBOutlet UIButton *buttonLoopTitleSel,*buttonLoopList,*buttonLoopListSel,*buttonShuffle,*buttonShuffleSel,*btnLoopInf;
	IBOutlet UIButton *infoButton,*backInfo,*infoZoom,*infoUnzoom;
	IBOutlet UIButton *mainRating1,*mainRating1off,*mainRating2,*mainRating2off,*mainRating3,*mainRating3off,*mainRating4,*mainRating4off,*mainRating5,*mainRating5off;
	IBOutlet UIToolbar *playBar,*pauseBar,*playBarSub,*pauseBarSub;	
    
    IBOutlet OBSlider *sliderProgressModule;
    
	IBOutlet UITextView *textMessage;
	IBOutlet UIView *infoMsgView;
	IBOutlet UILabel *infoMsgLbl,*infoSecMsgLbl;
	IBOutlet UIView *detailView,*commandViewU,*mainView,*infoView;
    
    
	
	IBOutlet UIButton *oglButton;

	IBOutlet UIView *volWin;
    
    IBOutlet UIImageView *cover_view,*gifAnimation;

	
    
    
	int sliderProgressModuleEdit;
	int sliderProgressModuleChanged;
	int 	module_waiting;
	NSTimer *repeatingTimer;
	
	CFont *mFont;
	CGLString *mText[128];
	CGLString *mTextLine[128];
	CGLString *viewTapInfoStr[9];
	CGLString *mHeader;
	
	int mDeviceType,mSlowDevice;
	
	short int real_spectrumL[SPECTRUM_BANDS*2],oreal_spectrumL[SPECTRUM_BANDS];
    int real_spectrumIL[SPECTRUM_BANDS];
    short int img_spectrumL[SPECTRUM_BANDS*2];
	short int real_spectrumR[SPECTRUM_BANDS*2],oreal_spectrumR[SPECTRUM_BANDS];
    int real_spectrumIR[SPECTRUM_BANDS];
    short int img_spectrumR[SPECTRUM_BANDS*2];
    int real_spectrumSumL[SPECTRUM_BANDS][8],real_spectrumSumR[SPECTRUM_BANDS][8];
	unsigned char real_beatDetectedL[SPECTRUM_BANDS];
	unsigned char real_beatDetectedR[SPECTRUM_BANDS];
	
	t_plPlaylist_entry *mPlaylist;
	int	mPlaylist_pos,mPlaylist_size;
	
	
	BOOL mShuffle;
    int mShouldUpdateInfos;
	int mLoopMode;
	int mMoveStartChanLeft;
	int mMoveStartChanRight;
	
	int mPlayingPosRestart;
	BOOL mIsPlaying;
	int mRestart,mRestart_sub,mRestart_arc;
	signed char mRating;
	
	int mShouldHaveFocus;
	
	int mHasFocus;
	float mScaleFactor;
	int mPaused;
}

@property t_plPlaylist_entry *mPlaylist;
//Cover flow
@property (retain,nonatomic) TKCoverflowView *coverflow; 
@property (retain,nonatomic) UILabel *lblMainCoverflow,*lblSecCoverflow,*lblCurrentSongCFlow,*lblTimeFCflow;
@property (retain,nonatomic) UIButton *btnPlayCFlow,*btnPauseCFlow,*btnBackCFlow,*btnNextCFlow,*btnPrevCFlow,*btnNextSubCFlow,*btnPrevSubCFlow;
@property BOOL mShuffle;
@property int mShouldUpdateInfos;

-(IBAction)pushedRating1;
-(IBAction)pushedRating2;
-(IBAction)pushedRating3;
-(IBAction)pushedRating4;
-(IBAction)pushedRating5;

-(IBAction)changeLoopMode;
-(IBAction)shuffle;

-(IBAction)pushedLoopInf;

-(IBAction)playNext;
-(IBAction)playPrev;
-(IBAction)playNextSub;
-(IBAction)playPrevSub;
-(void) longPressNextSubArc:(UIGestureRecognizer *)gestureRecognizer;
-(void) longPressPrevSubArc:(UIGestureRecognizer *)gestureRecognizer;

- (IBAction)showPlaylist;

- (IBAction)showInfo;
- (IBAction)hideInfo;
- (IBAction)infoFullscreen;
- (IBAction)infoNormal;

-(IBAction)AOSDK_OptChanged;
-(IBAction)SEXYPSF_OptChanged;
-(IBAction)ADPLUG_OptChanged;

- (void)showRating:(int)rating;
-(void) checkGLViewCanDisplay;

-(void)updateBarPos;

-(void)saveSettings;
-(void)loadSettings:(int)safe_mode;
-(void)updateFlagOnExit;
-(int)checkFlagOnStartup;

-(BOOL)play_curEntry;
-(void)play_nextEntry;
-(void)play_prevEntry;

-(void)play_restart;

-(void)play_listmodules:(t_playlist*)pl start_index:(int)index;
-(void)play_listmodules:(NSArray *)array start_index:(int)index path:(NSArray *)arrayFilepaths;

-(BOOL)play_module:(NSString *)filePath fname:(NSString *)fileName;

-(void) updateInfos: (NSTimer *) theTimer;
-(int) add_to_playlist:(NSString*)filePath fileName:(NSString*)fileName forcenoplay:(int)forcenoplay;
-(int) add_to_playlist:(NSArray *)filePaths fileNames:(NSArray*)fileNames forcenoplay:(int)forcenoplay;
-(void) remove_from_playlist:(int)index;

-(void) enterBackground;
-(void) enterForeground;


- (IBAction)sliderProgressModuleTest:(id)sender;
- (IBAction)sliderProgressModuleValueChanged:(id)sender;
- (IBAction)playPushed:(id)sender;
- (IBAction)pausePushed:(id)sender;
- (IBAction)settingsChanged:(id)sender;

-(IBAction) optUADE_Led;
-(IBAction) optUADE_Norm;
-(IBAction) optUADE_PostFX;
-(IBAction) optUADE_Pan;
-(IBAction) optUADE_Head;
-(IBAction) optUADE_Gain;
-(IBAction) optUADE_PanValue;
-(IBAction) optUADE_GainValue;
-(IBAction) optSID_Optim;
-(IBAction) optSID_LibVersion;
-(IBAction) optSID_Filter;

-(IBAction) oglButtonPushed;

@property 	int mShouldHaveFocus,mHasFocus,mPaused;
@property 	int mPlaylist_size,mPlaylist_pos,mSlowDevice,mDeviceType;
@property BOOL mIsPlaying;
@property float mScaleFactor;
@property (nonatomic, retain) ModizMusicPlayer *mplayer;
//@property (nonatomic,retain) NSMutableArray *mPlaylistFilenames,*mPlaylistFilepaths;
@property (nonatomic,retain) UIView *mInWasView;


//@property (retain) CLLocationManager *locManager;
@property (nonatomic, retain) IBOutlet UIView *infoMsgView;
@property (nonatomic, retain) IBOutlet UILabel *infoMsgLbl,*infoSecMsgLbl;
@property (nonatomic, retain) IBOutlet UISegmentedControl *sc_allowPopup;
@property (nonatomic, retain) IBOutlet UIButton *btnChangeTime;
@property (nonatomic, retain) IBOutlet UIView *mainView,*infoView;
@property (nonatomic, retain) IBOutlet UIButton *mainRating1,*mainRating1off,*mainRating2,*mainRating2off,*mainRating3,*mainRating3off,*mainRating4,*mainRating4off,*mainRating5,*mainRating5off;
@property (nonatomic, retain) IBOutlet UIButton *infoButton,*backInfo,*infoZoom,*infoUnzoom;
@property (nonatomic, retain) IBOutlet UIButton *oglButton;

@property (nonatomic, retain) IBOutlet UIPickerView *pvSubSongSel,*pvArcSel;

@property (nonatomic, retain) NSTimer *repeatingTimer;

@property (nonatomic, retain) IBOutlet UIView *detailView,*commandViewU,*volWin;

@property (nonatomic, retain) IBOutlet RRSGlowLabel *labelModuleName;
@property (nonatomic, retain) IBOutlet UILabel *labelNumChannels,*labelModuleType,*playlistPos,*labelLibName;
@property (nonatomic, retain) IBOutlet UILabel *labelTime,*labelModuleLength;
@property (nonatomic, retain) IBOutlet UILabel *labelSeeking;
@property (nonatomic, retain) IBOutlet UILabel *labelModuleSize;
@property (nonatomic, retain) IBOutlet UILabel *pvSubSongLabel,*pvArcLabel;
@property (nonatomic, retain) IBOutlet UIButton *pvSubSongValidate,*pvArcValidate;
@property (nonatomic, retain) IBOutlet BButton *btnShowArcList,*btnShowSubSong;
@property (nonatomic, retain) IBOutlet UIButton *buttonLoopTitleSel,*buttonLoopList,*buttonLoopListSel,*buttonShuffle,*buttonShuffleSel,*btnLoopInf;
@property (nonatomic, retain) IBOutlet UIToolbar *playBar,*pauseBar,*playBarSub,*pauseBarSub;
@property (nonatomic, retain) IBOutlet OBSlider *sliderProgressModule;
@property (nonatomic, retain) IBOutlet UISlider *surDepSld,*surDelSld,*revDepSld,*revDelSld,*bassAmoSld,*bassRanSld,*mastVolSld,*mpPanningSld;
@property (nonatomic, retain) IBOutlet UITextView *textMessage;

@property (nonatomic, retain) IBOutlet UISegmentedControl *sc_AOSDKDSFDSP,*sc_AOSDKDSFEmuRatio,*sc_AOSDKSSFDSP,*sc_AOSDKSSFEmuRatio,*sc_AOSDKDSF22KHZ;
@property (nonatomic, retain) IBOutlet UISegmentedControl *segcont_mpSampling,*segcont_mpMB,*segcont_mpReverb,*segcont_mpSUR;
//,*segcont_resumeLaunch
@property (nonatomic, retain) IBOutlet UISegmentedControl *sc_UADE_Led,*sc_UADE_Norm,*sc_UADE_PostFX,*sc_UADE_Pan,*sc_UADE_Head,*sc_UADE_Gain;
@property (nonatomic, retain) IBOutlet UISegmentedControl *sc_SEXYPSF_Reverb,*sc_SEXYPSF_Interpol;
@property (nonatomic, retain) IBOutlet UISegmentedControl *sc_AOSDK_Reverb,*sc_AOSDK_Interpol,*sc_SID_Optim,*sc_SID_LibVersion,*sc_SID_Filter;
@property (nonatomic, retain) IBOutlet UISegmentedControl *sc_ADPLUG_opltype;
@property (nonatomic, retain) IBOutlet UISlider *sld_UADEpan,*sld_UADEgain;


@property (nonatomic, retain) IBOutlet RootViewControllerLocalBrowser *rootViewControllerIphone;

@property (nonatomic, retain) IBOutlet UIImageView *cover_view,*gifAnimation;

-(IBAction) changeTimeDisplay;

-(IBAction) optAOSDK_DSF22KHZ;
-(IBAction) optAOSDK_DSFDSP;
-(IBAction) optAOSDK_DSFEmuRatio;
-(IBAction) optAOSDK_SSFDSP;
-(IBAction) optAOSDK_SSFEmuRatio;


-(IBAction)showSubSongSelector;
-(IBAction)playSelectedSubSong;
-(IBAction)showArcSelector;
-(IBAction)playSelectedArc;


- (void)titleTap:(UITapGestureRecognizer *)sender;

-(void) pushedRatingCommon:(short int)playcount;
-(void) hidePopup;
-(void) openPopup:(NSString *)msg secmsg:(NSString *)secmsg;
-(void) closePopup;
-(BOOL) play_loadArchiveModule;

-(NSString*) getCurrentModuleFilepath;

- (void) checkAvailableCovers;
- (void) checkAvailableCovers:(int)index;

- (void)animationDidStop:(NSString *)animationID finished:(NSNumber *)finished context:(void *)context;

-(void) loadDefaultSettings;

-(void)showWaiting;

-(void)hideWaiting;



@end
