--- third-party/credis-0.2.3/credis.c.orig	2013-11-18 21:41:06.000000000 +0600
+++ third-party/credis-0.2.3/credis.c	2013-11-18 21:41:54.000000000 +0600
@@ -39,6 +39,9 @@
 #include <winsock2.h>
 #include "ntop_win32.h"
 #else 
+#ifdef __FreeBSD__
+#include <sys/types.h>
+#endif
 #include <arpa/inet.h>
 #include <errno.h>
 #include <fcntl.h>
