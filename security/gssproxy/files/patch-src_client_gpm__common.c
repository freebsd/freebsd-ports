--- src/client/gpm_common.c.orig	2022-07-26 10:17:29 UTC
+++ src/client/gpm_common.c
@@ -2,6 +2,7 @@
 
 #include "gssapi_gpm.h"
 #include <sys/types.h>
+#include <sys/socket.h>
 #include <sys/un.h>
 #include <unistd.h>
 #include <stdlib.h>
@@ -11,6 +12,10 @@
 #include <fcntl.h>
 #include <sys/random.h>
 #include <sys/timerfd.h>
+
+#ifndef EBADFD
+#define EBADFD EBADF
+#endif
 
 #define FRAGMENT_BIT (1 << 31)
 
