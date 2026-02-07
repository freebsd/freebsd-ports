--- ICMPv6Socket.c.orig	2011-07-29 19:48:35.000000000 +0100
+++ ICMPv6Socket.c	2012-06-14 17:39:18.640973879 +0100
@@ -57,6 +57,10 @@ Tab Size = 8
 #include "ICMPv6Socket.h"
 #include <jni.h>

+#include <sys/socket.h>
+#include <netinet/in.h>
+#include <netinet/icmp6.h>
+
 #ifdef IP_MAXPACKET
 #define MAX_PACKET IP_MAXPACKET
 #else
