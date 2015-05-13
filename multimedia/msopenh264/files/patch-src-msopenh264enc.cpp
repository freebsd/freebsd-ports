--- src/msopenh264enc.cpp.orig	2015-03-16 09:14:32 UTC
+++ src/msopenh264enc.cpp
@@ -136,7 +136,7 @@ void MSOpenH264Encoder::initialize()
 			params.iRCMode = RC_BITRATE_MODE;
 			params.fMaxFrameRate = mVConf.fps;
 			params.uiIntraPeriod=mVConf.fps*10;
-			params.bEnableSpsPpsIdAddition=0;
+			params.eSpsPpsIdStrategy=CONSTANT_ID;
 			//params.bEnableRc = true;
 			params.bEnableFrameSkip = true;
 			params.bPrefixNalAddingCtrl = false;
