--- login_duo/login_duo.c.orig	2026-10-27 14:18:41 UTC
+++ login_duo/login_duo.c
@@ -28,6 +28,10 @@
 #include <arpa/inet.h>
 #include <openssl/crypto.h>
 #include <openssl/err.h>
+#ifdef __FreeBSD__
+#include <sys/socket.h>
+#include <netinet/in.h>
+#endif
 
 #include "util.h"
 #include "duo.h"
