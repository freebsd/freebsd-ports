--- io_wait.h.orig	2016-05-30 14:13:27 UTC
+++ io_wait.h
@@ -56,6 +56,9 @@
 
 #include <errno.h>
 #include <string.h>
+#if defined(__FreeBSD__)
+#include "ip_addr.h"
+#endif
 #ifdef HAVE_SIGIO_RT
 #define __USE_GNU /* or else F_SETSIG won't be included */
 #define _GNU_SOURCE /* define this as well */
