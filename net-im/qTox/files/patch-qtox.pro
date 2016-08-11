--- qtox.pro.orig	2016-04-24 12:44:18 UTC
+++ qtox.pro
@@ -49,11 +49,11 @@ include(translations/i18n.pri)
 system($$fromfile(translations/i18n.pri, updateallqm))
 
 isEmpty(GIT_VERSION) {
-    GIT_VERSION = $$system(git rev-parse HEAD 2> /dev/null || echo "built without git")
+    GIT_VERSION = $$system(echo "n/a")
 }
 DEFINES += GIT_VERSION=\"\\\"$$quote($$GIT_VERSION)\\\"\"
 isEmpty(GIT_DESCRIBE) {
-    GIT_DESCRIBE = $$system(git describe --tags 2> /dev/null || echo "Nightly")
+    GIT_DESCRIBE = $$FREEBSD_PKGVERSION
 }
 DEFINES += GIT_DESCRIBE=\"\\\"$$quote($$GIT_DESCRIBE)\\\"\"
 # date works on linux/mac, but it would hangs qmake on windows
@@ -485,6 +485,18 @@ SOURCES += \
     src/persistence/history.cpp \
     src/widget/form/groupinviteform.cpp
 
+unix {
+    target.path  = $$PREFIX/bin
+
+    desktop.files = qTox.desktop
+    desktop.path = $$PREFIX/share/applications
+
+    icon.files = img/qtox.png
+    icon.path = $$PREFIX/share/pixmaps
+
+    INSTALLS = target desktop icon
+}
+
 HEADERS += \
     src/audio/audio.h \
     src/core/core.h \
