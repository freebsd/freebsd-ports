--- xbmc/cores/dvdplayer/DVDCodecs/Video/VAAPI.cpp.orig	2015-05-11 07:54:22 UTC
+++ xbmc/cores/dvdplayer/DVDCodecs/Video/VAAPI.cpp
@@ -74,7 +74,7 @@ static inline VASurfaceID GetSurfaceID(A
 
 static CDisplayPtr GetGlobalDisplay()
 {
-  static weak_ptr<CDisplay> display_global;
+  static boost::weak_ptr<CDisplay> display_global;
 
   CDisplayPtr display(display_global.lock());
   if(display)
