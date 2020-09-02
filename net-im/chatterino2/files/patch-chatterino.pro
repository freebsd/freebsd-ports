--- chatterino.pro.orig	2020-08-31 14:42:30 UTC
+++ chatterino.pro
@@ -565,6 +567,21 @@ linux {
     target.path = $$PREFIX/bin
 
     INSTALLS += desktop build_icons icon target
+}
+
+freebsd {
+    desktop.path = $$PREFIX/share/applications
+    desktop.files = resources/com.chatterino.chatterino.desktop
+
+    xml.path = $$PREFIX/share/appdata
+    xml.files = resources/com.chatterino.chatterino.appdata.xml
+
+    icon.path = $$PREFIX/share/icons/hicolor/256x256/apps
+    icon.extra = cp $$PWD/resources/icon.png $(INSTALL_ROOT)/$$PREFIX/share/icons/hicolor/256x256/apps/chatterino.png
+
+    target.path = $$PREFIX/bin
+
+    INSTALLS += desktop icon target xml
 }
 
 git_commit=$$(GIT_COMMIT)
