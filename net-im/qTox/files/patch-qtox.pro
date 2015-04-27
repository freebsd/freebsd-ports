--- qtox.pro.orig	2015-04-27 03:03:27 UTC
+++ qtox.pro
@@ -433,6 +433,18 @@ SOURCES += \
     src/profilelocker.cpp \
     src/avatarbroadcaster.cpp
 
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
     src/audio.h \
     src/core/core.h \
