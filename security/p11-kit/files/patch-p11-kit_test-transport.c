--- p11-kit/test-transport.c.orig	2017-02-16 16:01:14 UTC
+++ p11-kit/test-transport.c
@@ -45,6 +45,7 @@
 
 #include <errno.h>
 #include <sys/types.h>
+#include <signal.h>
 #ifdef OS_UNIX
 #include <sys/socket.h>
 #include <sys/un.h>
