--- core/DesktopEditor/graphics/pro/graphics.pro.orig	2021-12-18 11:22:47 UTC
+++ core/DesktopEditor/graphics/pro/graphics.pro
@@ -35,6 +35,11 @@ DEFINES += \
 
 DEFINES += FT_SUPPORT_UTF8_IN_NAMES
 
+core_freebsd {
+    DEFINES += HAVE_UNISTD_H HAVE_FCNTL_H
+    QMAKE_CXXFLAGS += -Wno-narrowing
+}
+
 core_linux {
     DEFINES += HAVE_UNISTD_H HAVE_FCNTL_H
     QMAKE_CXXFLAGS += -Wno-narrowing
