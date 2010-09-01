--- kplayer/kplayerengine.h.orig	2010-06-15 14:26:22.055340072 +0300
+++ kplayer/kplayerengine.h	2010-06-15 14:23:27.311957650 +0300
@@ -559,26 +559,31 @@ inline KPlayerEngine* kPlayerEngine (voi
 
 inline KPlayerProcess* kPlayerProcess (void)
 {
+  if ( kPlayerEngine() == 0 ) return 0;
   return kPlayerEngine() -> process();
 }
 
 inline KConfig* kPlayerConfig (void)
 {
+  if ( kPlayerEngine() == 0 ) return 0;
   return kPlayerEngine() -> config();
 }
 
 inline KPlayerSettings* kPlayerSettings (void)
 {
+  if ( kPlayerEngine() == 0 ) return 0;
   return kPlayerEngine() -> settings();
 }
 
 inline KPlayerWidget* kPlayerWidget (void)
 {
+  if ( kPlayerEngine() == 0 ) return 0;
   return kPlayerEngine() -> widget();
 }
 
 inline KPlayerWorkspace* kPlayerWorkspace (void)
 {
+  if ( kPlayerEngine() == 0 ) return 0;
   return kPlayerEngine() -> workspace();
 }
 
