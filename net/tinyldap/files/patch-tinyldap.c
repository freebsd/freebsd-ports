--- tinyldap.c.orig	Thu Feb  5 02:29:18 2004
+++ tinyldap.c	Thu Feb 26 16:03:58 2004
@@ -14,7 +14,12 @@
 #ifdef STANDALONE
 #include "socket.h"
 #include "ip6.h"
+#ifdef __FreeBSD__
+#include <sys/types.h>
+#include <sys/wait.h>
+#else
 #include <wait.h>
+#endif
 #endif
 #include "case.h"
 #include <signal.h>
