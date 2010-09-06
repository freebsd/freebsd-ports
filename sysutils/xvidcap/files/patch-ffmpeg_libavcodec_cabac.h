--- ffmpeg/libavcodec/cabac.h.orig	2010-08-29 11:27:54.000000000 +0000
+++ ffmpeg/libavcodec/cabac.h	2010-08-29 11:28:07.000000000 +0000
@@ -28,9 +28,6 @@
 
 //#undef NDEBUG
 #include <assert.h>
-#ifdef ARCH_X86_64
-#define ARCH_X86
-#endif
 #ifdef ARCH_X86
 #include "x86_cpu.h"
 #endif
