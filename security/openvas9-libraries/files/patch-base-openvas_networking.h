--- base/openvas_networking.h.orig	2015-12-08 07:07:23 UTC
+++ base/openvas_networking.h
@@ -28,6 +28,7 @@
 #include <string.h>
 #include <arpa/inet.h>
 #include <net/if.h>
+#include <netinet/in.h>
 #include <sys/types.h>
 #include <ifaddrs.h>
 #include <netdb.h>
