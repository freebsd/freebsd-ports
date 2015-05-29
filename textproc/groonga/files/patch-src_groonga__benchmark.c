--- src/groonga_benchmark.c.orig	2015-05-29 10:18:15 UTC
+++ src/groonga_benchmark.c
@@ -51,6 +51,9 @@
 #include <libgen.h>
 #endif /* WIN32 */
 
+#if defined(__FreeBSD__) || defined(__DragonFly__)
+#include <netinet/in.h>
+#endif
 /*
 #define DEBUG_FTP
 #define DEBUG_HTTP
