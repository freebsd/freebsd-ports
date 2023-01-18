--- client_examples/sshtunnel.c.orig	2023-01-18 22:59:01 UTC
+++ client_examples/sshtunnel.c
@@ -16,6 +16,9 @@
 #include <netdb.h>
 #include <signal.h>
 #include <errno.h>
+#ifdef __FreeBSD__
+#include <sys/socket.h>
+#endif
 
 /* The one global bool that's global so we can set it via
    a signal handler... */
