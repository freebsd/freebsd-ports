--- iface.c.orig	Wed Aug 18 16:09:25 2004
+++ iface.c	Wed Aug 18 16:11:38 2004
@@ -32,6 +32,15 @@
 #include <sys/wait.h>
 #include <sys/types.h>
 
+#ifndef TEMP_FAILURE_RETRY
+#define TEMP_FAILURE_RETRY(expression)                           \
+         (__extension__                                          \
+          ({ long int __result;                                  \
+                 do __result = (long int) (expression);          \
+                 while (__result == -1L && errno == EINTR);      \
+                 __result; }))
+#endif
+
 extern int getresgid (gid_t *rgid, gid_t *egid, gid_t *sgid);
 
 #include "utempter.h"
