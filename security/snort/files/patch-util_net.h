--- src/sfutil/util_net.h.orig	Fri Dec 19 14:32:47 2003
+++ src/sfutil/util_net.h	Fri Dec 19 14:34:31 2003
@@ -11,7 +11,12 @@
 #ifndef _UTIL_NET_H
 #define _UTIL_NET_H
 
-#include <stdint.h>
+
+#if HAVE_STDINT_H
+ #include <stdint.h>
+#else
+ #include <inttypes.h>
+#endif
 
 char *inet_ntoax(uint32_t ip);
 char * mktcpflag_str(int flags);
