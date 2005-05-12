--- libavformat/udp.c.orig	Tue May 10 01:08:33 2005
+++ libavformat/udp.c	Tue May 10 01:09:27 2005
@@ -27,6 +27,10 @@
 # include "barpainet.h"
 #endif
 #include <netdb.h>
+#ifndef IPV6_ADD_MEMBERSHIP
+#define IPV6_ADD_MEMBERSHIP IPV6_JOIN_GROUP
+#define IPV6_DROP_MEMBERSHIP IPV6_LEAVE_GROUP
+#endif
 
 typedef struct {
     int udp_fd;
