--- src/layer3.c.orig	2018-09-15 19:08:05 UTC
+++ src/layer3.c
@@ -16,6 +16,13 @@
 #include <sys/socket.h>
 #endif
 
+#ifdef __FreeBSD__
+#include <sys/types.h>
+#include <netinet/in_systm.h>
+#include <netinet/in.h>
+#include <sys/socket.h>
+#endif
+
 #include <netinet/ip.h>
 #include <netinet/ip6.h>
 
