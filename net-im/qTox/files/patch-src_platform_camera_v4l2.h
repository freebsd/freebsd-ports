--- src/platform/camera/v4l2.h.orig	2015-11-14 22:51:30 UTC
+++ src/platform/camera/v4l2.h
@@ -24,7 +24,7 @@
 #include <QPair>
 #include "src/video/videomode.h"
 
-#ifndef Q_OS_LINUX
+#ifndef Q_OS_UNIX
 #error "This file is only meant to be compiled for Linux targets"
 #endif
 
