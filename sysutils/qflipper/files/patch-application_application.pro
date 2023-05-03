--- application/application.pro.orig	2023-03-27 09:51:38 UTC
+++ application/application.pro
@@ -109,8 +109,8 @@ unix:!macx {
     iconfiles.files = $$PWD/assets/icons/$${TARGET}.png
     iconfiles.path = $$PREFIX/share/icons/hicolor/512x512/apps
 
-    udevfiles.files = $$PWD/../installer-assets/udev/42-flipperzero.rules
-    udevfiles.path = $$PREFIX/lib/udev/rules.d
+    #udevfiles.files = $$PWD/../installer-assets/udev/42-flipperzero.rules
+    #udevfiles.path = $$PREFIX/lib/udev/rules.d
 
     INSTALLS += target desktopfiles iconfiles udevfiles
 
