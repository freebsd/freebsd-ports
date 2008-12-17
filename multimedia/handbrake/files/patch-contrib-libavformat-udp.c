--- contrib/ffmpeg/libavformat/udp.c.orig	2008-11-28 11:10:53.217812028 -0500
+++ contrib/ffmpeg/libavformat/udp.c	2008-11-28 11:11:20.566271071 -0500
@@ -29,6 +29,7 @@
 #include <unistd.h>
 #include "network.h"
 #include "os_support.h"
+#define IPPROTO_IPV6            41              /* IP6 header */
 
 #ifndef IPV6_ADD_MEMBERSHIP
 #define IPV6_ADD_MEMBERSHIP IPV6_JOIN_GROUP
