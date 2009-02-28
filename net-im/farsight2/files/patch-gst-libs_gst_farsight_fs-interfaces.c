--- gst-libs/gst/farsight/fs-interfaces.c.orig	2009-02-27 23:28:15.000000000 -0500
+++ gst-libs/gst/farsight/fs-interfaces.c	2009-02-27 23:28:33.000000000 -0500
@@ -46,6 +46,7 @@ GST_DEBUG_CATEGORY_EXTERN (fs_base_confe
  #include <sys/socket.h>
  #include <ifaddrs.h>
 #endif
+#include <netinet/in.h>
 #include <net/if.h>
 #include <net/if_arp.h>
 #include <arpa/inet.h>
