--- gst-libs/gst/farsight/fs-interfaces.c.orig	2010-05-22 03:04:56.000000000 -0400
+++ gst-libs/gst/farsight/fs-interfaces.c	2010-05-22 03:08:16.000000000 -0400
@@ -30,10 +30,7 @@
 
 #ifdef G_OS_UNIX
 
-#include <arpa/inet.h>
 #include <errno.h>
-#include <net/if.h>
-#include <net/if_arp.h>
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
@@ -44,6 +41,10 @@
  #include <sys/socket.h>
  #include <ifaddrs.h>
 #endif
+#include <netinet/in.h>
+#include <arpa/inet.h>
+#include <net/if.h>
+#include <net/if_arp.h>
 
 #include <gst/gst.h>
 
