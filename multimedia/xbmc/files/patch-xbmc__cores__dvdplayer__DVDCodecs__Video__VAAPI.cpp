--- xbmc/cores/dvdplayer/DVDCodecs/Video/VAAPI.cpp.orig	2013-10-19 23:07:02.530131780 +0200
+++ xbmc/cores/dvdplayer/DVDCodecs/Video/VAAPI.cpp	2013-10-19 23:06:38.499626784 +0200
@@ -74,7 +74,7 @@
 
 static CDisplayPtr GetGlobalDisplay()
 {
-  static weak_ptr<CDisplay> display_global;
+  static boost::weak_ptr<CDisplay> display_global;
 
   CDisplayPtr display(display_global.lock());
   if(display)
