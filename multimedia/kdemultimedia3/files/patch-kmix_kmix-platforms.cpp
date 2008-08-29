--- ./kmix/kmix-platforms.cpp.orig	2008-08-27 12:50:03.000000000 +0400
+++ ./kmix/kmix-platforms.cpp	2008-08-27 13:20:36.000000000 +0400
@@ -84,10 +84,6 @@
 #else
 #include <soundcard.h>
 #endif
-#if SOUND_VERSION >= 0x040000
-#define OSS4_MIXER
-#undef OSS_MIXER
-#endif
 
 #endif
 
