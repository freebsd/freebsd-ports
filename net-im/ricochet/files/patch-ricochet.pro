--- ricochet.pro.orig	2015-06-17 04:00:47 UTC
+++ ricochet.pro
@@ -46,18 +46,18 @@ CONFIG(release,debug|release):DEFINES +=
 
 contains(DEFINES, RICOCHET_NO_PORTABLE) {
     unix:!macx {
-        target.path = /usr/bin
-        shortcut.path = /usr/share/applications
+        target.path = $$PREFIX/bin
+        shortcut.path = $$PREFIX/share/applications
         shortcut.files = src/ricochet.desktop
-        icon.path = /usr/share/icons/hicolor/48x48/apps/
+        icon.path = $$PREFIX/share/icons/hicolor/48x48/apps/
         icon.files = icons/ricochet.png
-        scalable_icon.path = /usr/share/icons/hicolor/scalable/apps/
+        scalable_icon.path = $$PREFIX/share/icons/hicolor/scalable/apps/
         scalable_icon.files = icons/ricochet.svg
         INSTALLS += target shortcut icon scalable_icon
 
         exists(tor) {
             message(Adding bundled Tor to installations)
-            bundletor.path = /usr/lib/ricochet/tor/
+            bundletor.path = $$PREFIX/lib/ricochet/tor/
             bundletor.files = tor/*
             INSTALLS += bundletor
             DEFINES += BUNDLED_TOR_PATH=\\\"/usr/lib/ricochet/tor/\\\"
