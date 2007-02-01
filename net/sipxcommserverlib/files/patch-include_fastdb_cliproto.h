--- ./include/fastdb/cliproto.h.orig	Thu Dec 28 18:47:56 2006
+++ ./include/fastdb/cliproto.h	Thu Dec 28 18:49:16 2006
@@ -81,10 +81,7 @@
     cli_oid
 };
 
-#if defined(__FreeBSD__)
-#include <sys/param.h>
-#define USE_HTON_NTOH
-#elif defined(__linux__)
+#if defined(__linux__) || defined(__FreeBSD__)
 //
 // At Linux inline assembly declarations of ntohl, htonl... are available
 //
