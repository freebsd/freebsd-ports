--- src/transmit.c.orig	Sat Nov 30 03:27:16 2002
+++ src/transmit.c	Wed Dec 18 03:30:45 2002
@@ -45,8 +45,8 @@
 #endif /* !PLATFORM_WINNT */
 
 #if !defined PLATFORM_WINNT && !defined PLATFORM_BEOS
-#   include <arpa/inet.h>       /* htons(), in_addr_t */
 #   include <netinet/in.h>
+#   include <arpa/inet.h>       /* htons(), in_addr_t */
 #endif
 /* Some Linux with old system headers might need this */
 /* #if defined PLATFORM_LINUX
