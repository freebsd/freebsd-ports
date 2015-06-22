--- qtox.pro.orig	2015-06-12 10:53:59 UTC
+++ qtox.pro
@@ -483,6 +483,18 @@ SOURCES += \
     src/widget/translator.cpp \
     src/persistence/settingsserializer.cpp
 
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
