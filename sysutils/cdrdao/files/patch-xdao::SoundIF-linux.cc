--- xdao/SoundIF-linux.cc.orig	Mon Oct  7 03:53:56 2002
+++ xdao/SoundIF-linux.cc	Sat Oct 12 17:32:10 2002
@@ -34,7 +34,14 @@
  *
  */
 
+# if defined(__FreeBSD__)
+#include <sys/soundcard.h>
+# if !defined(SNDCTL_DSP_CHANNELS)
+#   define SNDCTL_DSP_CHANNELS SNDCTL_DSP_STEREO
+# endif
+# else 
 #include <linux/soundcard.h>
+# endif
 
 #include <stdio.h>
 #include <assert.h>
