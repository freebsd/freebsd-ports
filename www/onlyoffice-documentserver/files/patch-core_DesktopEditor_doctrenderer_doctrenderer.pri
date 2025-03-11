--- ./core/DesktopEditor/doctrenderer/doctrenderer.pri.orig	2025-03-07 15:39:12.468049000 +0100
+++ ./core/DesktopEditor/doctrenderer/doctrenderer.pri	2025-03-07 15:38:54.771039000 +0100
@@ -22,6 +22,10 @@ core_android:DEFINES += DISABLE_MEMORY_LIMITATION
 #CONFIG += v8_version_60
 core_android:DEFINES += DISABLE_MEMORY_LIMITATION
 
+core_freebsd {
+    LIBS += -lexecinfo
+}
+
 HEADERS += \
 	$$PWD_CUR/config.h \
 	$$PWD_CUR/editors.h \
