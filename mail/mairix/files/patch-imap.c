--- imap.c.orig	2018-02-20 18:43:53 UTC
+++ imap.c
@@ -9,11 +9,15 @@
 #include <time.h>
 #include <poll.h>
 #include <signal.h>
+#include <sys/socket.h>
 #include <sys/wait.h>
 #ifdef USE_OPENSSL
 #include <openssl/ssl.h>
 #include <openssl/err.h>
 #endif
+#if defined(__FreeBSD__)
+#define __BSD_VISIBLE 1
+#endif
 #include "imap.h"
 
 struct imap_ll {
