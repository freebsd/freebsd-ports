--- ricochet.pro.orig	2016-11-04 22:05:33 UTC
+++ ricochet.pro
@@ -52,18 +52,18 @@ CONFIG(release,debug|release):DEFINES +=
 
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
@@ -108,7 +108,10 @@ INCLUDEPATH += src
 
 unix {
     !isEmpty(OPENSSLDIR) {
-        INCLUDEPATH += $${OPENSSLDIR}/include
+        !equals(OPENSSLDIR, "/usr") {
+            # adding /usr/include to INCLUDEPATH breaks STL's include logic
+            INCLUDEPATH += $${OPENSSLDIR}/include
+        }
         LIBS += -L$${OPENSSLDIR}/lib -lcrypto
     } else:macx:!packagesExist(libcrypto) {
         # Fall back to the OS-provided 0.9.8 if no other libcrypto is present
