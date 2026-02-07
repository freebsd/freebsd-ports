--- core/DesktopEditor/doctrenderer/doctrenderer.pri.orig	2025-08-02 18:33:34 UTC
+++ core/DesktopEditor/doctrenderer/doctrenderer.pri
@@ -22,6 +22,10 @@ ADD_DEPENDENCY(graphics, kernel, UnicodeConverter, ker
 #CONFIG += v8_version_60
 core_android:DEFINES += DISABLE_MEMORY_LIMITATION
 
+core_freebsd {
+    LIBS += -lexecinfo
+}
+
 HEADERS += \
 	$$PWD_CUR/config.h \
 	$$PWD_CUR/editors.h \
