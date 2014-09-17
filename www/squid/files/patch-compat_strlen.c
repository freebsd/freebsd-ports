--- compat/strlen.c.orig	2014-01-26 23:28:26.000000000 -0700
+++ compat/strlen.c	2014-01-26 23:33:01.000000000 -0700
@@ -0,0 +1,28 @@
+/* Dennis Glatting
+   January 2014   
+
+   Various places within Squid call strlen() with a NULL pointer,
+   which causes a SIGSEV on FreeBSD. This is a simple, dumb
+   replacement that first checks for a NULL pointer before counting
+   the string's length. In the case of a NULL pointer, the string's
+   length is 0.
+
+ */
+
+
+#include "squid.h"
+#include <string.h>
+
+size_t
+strlen( const char* s ) {
+
+  size_t c = 0;
+
+  if( s == NULL )
+    return 0;
+
+  while( *s++ )
+    ++c;
+
+    return c;
+}
