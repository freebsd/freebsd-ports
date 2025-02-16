--- posix/posix.c.orig	2025-02-16 14:38:30 UTC
+++ posix/posix.c
@@ -7,10 +7,6 @@
  * (at your option) any later version.
  */

-#define _POSIX_C_SOURCE 200809L /* fstatat() */
-#define _DEFAULT_SOURCE         /* DT_* */
-#define _BSD_SOURCE             /* DT_* */
-
 #include "posix.h"
 #include "../containers/containers.h" /* schemesh_Sbytevector() */
 #include "../eval.h"                  /* eval() */
@@ -817,8 +813,14 @@ static ptr c_get_hostname(void) {

 /** return Scheme string, or Scheme integer on error */
 static ptr c_get_hostname(void) {
+#ifdef __FreeBSD__
+  int len = sysconf(_SC_HOST_NAME_MAX) + 1;
+  char* buf = alloca(len);
+  if (gethostname(buf, len) != 0) {
+#else
   char buf[HOST_NAME_MAX + 1];
   if (gethostname(buf, sizeof(buf)) != 0) {
+#endif
     return Sinteger(c_errno());
   }
   return schemesh_Sstring_utf8b(buf, -1);
