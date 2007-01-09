--- mplayerxp/sig_hand.h.orig	Mon Jan 17 03:39:59 2005
+++ mplayerxp/sig_hand.h	Sun Oct  1 21:26:33 2006
@@ -5,6 +5,7 @@
 #define __SIG_HAND_H 1
 
 #include <sys/types.h>
+#include <pthread.h>
 
 #define MAX_XPTHREADS 16
 
