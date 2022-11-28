--- application/application.pro.orig	2022-11-27 22:12:16 UTC
+++ application/application.pro
@@ -100,8 +100,8 @@ unix:!macx {
     iconfiles.files = $$PWD/assets/icons/$${TARGET}.png
     iconfiles.path = $$PREFIX/share/icons/hicolor/512x512/apps
 
-    udevfiles.files = $$PWD/../installer-assets/udev/42-flipperzero.rules
-    udevfiles.path = $$PREFIX/lib/udev/rules.d
+    #udevfiles.files = $$PWD/../installer-assets/udev/42-flipperzero.rules
+    #udevfiles.path = $$PREFIX/lib/udev/rules.d
 
     INSTALLS += target desktopfiles iconfiles udevfiles
 
