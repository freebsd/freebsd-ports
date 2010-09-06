--- ffmpeg/libavformat/grab_bktr.c~	2010-08-29 11:31:58.000000000 +0000
+++ ffmpeg/libavformat/grab_bktr.c	2010-08-29 11:32:13.000000000 +0000
@@ -25,13 +25,8 @@
  */
 #include "avformat.h"
 #if defined(__FreeBSD__)
-# if __FreeBSD__ >= 502100
 #  include <dev/bktr/ioctl_meteor.h>
 #  include <dev/bktr/ioctl_bt848.h>
-# else
-#  include <machine/ioctl_meteor.h>
-#  include <machine/ioctl_bt848.h>
-# endif
 #elif defined(__FreeBSD_kernel__)
 # include <dev/bktr/ioctl_meteor.h>
 # include <dev/bktr/ioctl_bt848.h>
