--- src/xt.c.orig	Mon Sep 17 00:39:58 2001
+++ src/xt.c	Mon Sep 17 00:40:07 2001
@@ -27,6 +27,13 @@
 # include <linux/videodev.h>
 #endif
 
+#if defined(__FreeBSD__)
+#define VIDEO_SOUND_MONO        1
+#define VIDEO_SOUND_STEREO      2
+#define VIDEO_SOUND_LANG1       4
+#define VIDEO_SOUND_LANG2       8
+#endif
+
 #include "config.h"
 
 #include <X11/Xlib.h>

