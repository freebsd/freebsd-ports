--- src/eventmanager.c.orig	2008-06-21 09:03:33.000000000 +1000
+++ src/eventmanager.c	2008-06-21 09:03:46.000000000 +1000
@@ -35,7 +35,7 @@
 #include <sys/socket.h>
 #include <netinet/in.h>
 #include <arpa/inet.h>
-#include <linux/if.h>
+#include <net/if.h>
 #include <sys/ioctl.h>
 
 #include "eventmanager.h"
