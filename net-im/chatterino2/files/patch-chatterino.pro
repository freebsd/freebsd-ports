--- chatterino.pro.orig	2021-05-16 17:29:27 UTC
+++ chatterino.pro
@@ -624,6 +624,21 @@ linux {
     INSTALLS += desktop build_icons icon target
 }
 
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
+}
+
 git_commit=$$(GIT_COMMIT)
 git_release=$$(GIT_RELEASE)
 # Git data
