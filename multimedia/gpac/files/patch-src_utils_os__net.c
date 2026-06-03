--- src/utils/os_net.c.orig	2026-01-10 11:16:13 UTC
+++ src/utils/os_net.c
@@ -130,6 +130,9 @@ static int wsa_init = 0;
 #include <sys/types.h>
 #include <arpa/inet.h>
 
+#if defined(__FreeBSD__)
+#include <sys/stat.h>
+#endif
 
 /*not defined on solaris*/
 #if !defined(INADDR_NONE)
