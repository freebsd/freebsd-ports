--- src/nd.h.orig	Sat Oct 12 00:03:36 2002
+++ src/nd.h	Sat Oct 12 00:03:59 2002
@@ -31,6 +31,7 @@
 #ifdef LINUX
 #define __FAVOR_BSD
 #endif
+#include <sys/types.h>
 #include <netinet/in_systm.h>
 #include <netinet/in.h>
 
