--- mplayerxp/mplayer.c.orig	Thu Nov 30 15:30:08 2006
+++ mplayerxp/mplayer.c	Mon Dec 25 01:37:46 2006
@@ -9,8 +9,8 @@
 #define __USE_ISOC99 1 /* for lrint */
 #include <math.h>
 #include <errno.h>
-#include <sys/mman.h>
 #include <sys/types.h>
+#include <sys/mman.h>
 #include <sys/wait.h>
 #include <sys/time.h>
 #include <sys/stat.h>
