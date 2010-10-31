--- lib/krb5/name-45-test.c.orig	2010-10-15 14:18:52.000000000 +0200
+++ lib/krb5/name-45-test.c	2010-10-15 14:21:45.000000000 +0200
@@ -35,6 +35,8 @@
 #include "krb5_locl.h"
 #include <err.h>
 
+#ifdef KRB4
+
 enum { MAX_COMPONENTS = 3 };
 
 static struct testcase {
@@ -292,3 +294,9 @@
     }
     return val;
 }
+
+#else /* stub for !KRB4 */
+int main(int argc, char *argv[]) {
+  return 77;
+}
+#endif
