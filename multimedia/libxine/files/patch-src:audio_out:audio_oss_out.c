--- src/audio_out/audio_oss_out.c.orig	Sun Jun  2 01:54:46 2002
+++ src/audio_out/audio_oss_out.c	Sun Jun  2 01:55:37 2002
@@ -51,6 +51,8 @@
 #elif defined (__FreeBSD__)
 #  if __FreeBSD__ < 4
 #   include <machine/soundcard.h>
+#  else
+#   include <sys/soundcard.h>
 #  endif
 #else
 # if defined(__linux__)
