--- mplayerxp/mplayer.h.orig	Thu Jul 21 17:08:10 2005
+++ mplayerxp/mplayer.h	Sun Oct  1 21:27:24 2006
@@ -1,6 +1,8 @@
 #ifndef __MPLAYERXP_MAIN
 #define __MPLAYERXP_MAIN 1
 
+#include <pthread.h>
+
 typedef struct initial_audio_pts_correction_s
 {
     int need_correction;
