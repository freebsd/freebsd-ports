--- libao/audio_out_oss.c.orig	Thu Feb  5 10:14:12 2004
+++ libao/audio_out_oss.c	Wed May 12 11:49:35 2004
@@ -34,8 +34,9 @@
 
 #if defined(__OpenBSD__) || defined(__NetBSD__)
 #include <soundcard.h>
-#elif defined(__FreeBSD__)
-#include <machine/soundcard.h>
+#else
+#include <sys/soundcard.h>
+#if defined(__FreeBSD__)
 #ifndef AFMT_S16_NE
 #include <machine/endian.h>
 #if BYTE_ORDER == LITTLE_ENDIAN
@@ -44,8 +45,7 @@
 #define AFMT_S16_NE AFMT_S16_BE
 #endif
 #endif
-#else
-#include <sys/soundcard.h>
+#endif
 #endif
 
 #if defined(__NetBSD__)
