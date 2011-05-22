--- relayd.orig/carp.c	2011-05-22 01:06:39.463154237 +0200
+++ relayd/carp.c	2011-05-22 01:06:54.671017027 +0200
@@ -19,6 +19,7 @@
 #include <sys/param.h>
 #include <sys/socket.h>
 #include <sys/ioctl.h>
+#include <sys/queue.h>
 
 #include <net/if.h>
 
