--- kplayer/kplayer.cpp~	Sat Jul 26 15:49:07 2003
+++ kplayer/kplayer.cpp	Sun Aug  3 10:36:45 2003
@@ -395,7 +395,7 @@
   setSaturation (value);
   if ( kPlayerProcess() -> length() > 0 )
     sliderAction ("player_progress") -> slider() ->
-      setPageStep (int (roundf (kPlayerProcess() -> length() * settings -> progressMarks())));
+      setPageStep (int (rintf (kPlayerProcess() -> length() * settings -> progressMarks())));
   QApplication::postEvent (this, new QEvent (QEvent::LayoutHint));
 //layout() -> activate();
   recentFilesAction() -> setMaxItems (settings -> recentFileListSize());
@@ -1192,7 +1192,7 @@
   KPlayerSettings* settings = kPlayerSettings();
   int seek = settings -> progressNormalSeekUnits() ? settings -> progressNormalSeek() :
     kPlayerProcess() -> length() == 0 ? 10 :
-    int (roundf (kPlayerProcess() -> length() * settings -> progressNormalSeek() / 100));
+    int (rintf (kPlayerProcess() -> length() * settings -> progressNormalSeek() / 100));
   if ( seek == 0 )
     seek = 1;
   kPlayerProcess() -> relativeSeek (seek);
@@ -1203,7 +1203,7 @@
   KPlayerSettings* settings = kPlayerSettings();
   int seek = settings -> progressFastSeekUnits() ? settings -> progressFastSeek() :
     kPlayerProcess() -> length() == 0 ? 60 :
-    int (roundf (kPlayerProcess() -> length() * settings -> progressFastSeek() / 100));
+    int (rintf (kPlayerProcess() -> length() * settings -> progressFastSeek() / 100));
   if ( seek == 0 )
     seek = 2;
   kPlayerProcess() -> relativeSeek (seek);
@@ -1214,7 +1214,7 @@
   KPlayerSettings* settings = kPlayerSettings();
   int seek = settings -> progressNormalSeekUnits() ? settings -> progressNormalSeek() :
     kPlayerProcess() -> length() == 0 ? 10 :
-    int (roundf (kPlayerProcess() -> length() * settings -> progressNormalSeek() / 100));
+    int (rintf (kPlayerProcess() -> length() * settings -> progressNormalSeek() / 100));
   if ( seek == 0 )
     seek = 1;
   kPlayerProcess() -> relativeSeek (- seek);
@@ -1225,7 +1225,7 @@
   KPlayerSettings* settings = kPlayerSettings();
   int seek = settings -> progressFastSeekUnits() ? settings -> progressFastSeek() :
     kPlayerProcess() -> length() == 0 ? 60 :
-    int (roundf (kPlayerProcess() -> length() * settings -> progressFastSeek() / 100));
+    int (rintf (kPlayerProcess() -> length() * settings -> progressFastSeek() / 100));
   if ( seek == 0 )
     seek = 2;
   kPlayerProcess() -> relativeSeek (- seek);
@@ -1586,7 +1586,7 @@
     return;
   kdDebug() << "Seek to " << progress << ": " << kPlayerProcess() -> position() << " => " << ((progress + 50) / 100) << " / " << kPlayerProcess() -> length() << "\n";
   kPlayerProcess() -> absoluteSeek ((progress + 50) / 100);
-/*int seek = int (roundf (float (progress) / 100 - kPlayerProcess() -> position()));
+/*int seek = int (rintf (float (progress) / 100 - kPlayerProcess() -> position()));
   if ( seek == 0 )
     return;
   kPlayerProcess() -> relativeSeek (seek);*/
@@ -1714,7 +1714,7 @@
   int maxValue = slider -> maxValue();
   if ( maxValue )
   {
-    int value = int (roundf (progress * 100));
+    int value = int (rintf (progress * 100));
     if ( value > maxValue )
       slider -> setMaxValue (value);
     slider -> setValue (value);
@@ -1757,8 +1757,8 @@
   KPlayerSettings* settings = kPlayerSettings();
   kdDebug() << "Info available. Detected length: " << kPlayerProcess() -> length() << "\n";
   KPlayerSlider* slider = sliderAction ("player_progress") -> slider();
-  slider -> setMaxValue (int (roundf (kPlayerProcess() -> length() * 100)));
-  slider -> setPageStep (int (roundf (kPlayerProcess() -> length() * settings -> progressMarks())));
+  slider -> setMaxValue (int (rintf (kPlayerProcess() -> length() * 100)));
+  slider -> setPageStep (int (rintf (kPlayerProcess() -> length() * settings -> progressMarks())));
   enablePlayerActions();
 }
 
