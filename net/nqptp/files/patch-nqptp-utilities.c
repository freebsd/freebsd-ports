--- nqptp-utilities.c.orig	2023-09-16 17:51:55 UTC
+++ nqptp-utilities.c
@@ -29,10 +29,10 @@
 #endif
 
 #ifdef CONFIG_FOR_FREEBSD
+#include <sys/types.h>
 #include <net/if_dl.h>
 #include <net/if_types.h>
 #include <sys/socket.h>
-#include <sys/types.h>
 #include <unistd.h>
 #endif
 
