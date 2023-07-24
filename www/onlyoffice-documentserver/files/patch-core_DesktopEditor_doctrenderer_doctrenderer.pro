--- core/DesktopEditor/doctrenderer/doctrenderer.pro.orig	2021-09-30 12:13:32 UTC
+++ core/DesktopEditor/doctrenderer/doctrenderer.pro	2021-09-30 12:13:32 UTC
@@ -18,6 +18,10 @@ core_android:DEFINES += DISABLE_MEMORY_LIMITATION
 #CONFIG += build_xp
 core_android:DEFINES += DISABLE_MEMORY_LIMITATION
 
+core_freebsd {
+    LIBS += -lexecinfo
+}
+
 HEADERS += \
     config.h \
     doctrenderer.h \
