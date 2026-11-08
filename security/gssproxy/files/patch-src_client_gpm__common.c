--- src/client/gpm_common.c.orig	2026-10-20 15:29:35 UTC
+++ src/client/gpm_common.c
@@ -2,6 +2,7 @@
 
 #include "gssapi_gpm.h"
 #include <sys/types.h>
+#include <sys/socket.h>
 #include <sys/un.h>
 #include <unistd.h>
 #include <stdlib.h>
@@ -13,6 +14,10 @@
 #include <sys/random.h>
 #include <sys/timerfd.h>
 
+#ifndef EBADFD
+#define EBADFD EBADF
+#endif
+
 #define FRAGMENT_BIT (1 << 31)
 
 #define RESPONSE_TIMEOUT 15
@@ -92,7 +97,11 @@ static int get_pipe_name(char *name)
     int ret = 1;
 
     /* check if this is a "secure" client */
+#ifdef __FreeBSD__
+    auxval = issetugid() ? 1 : 0;
+#else
     auxval = getauxval(AT_SECURE);
+#endif
 
     if (auxval == 0) {
         /* default case */
