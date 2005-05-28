--- response.c.orig	Thu Jun 10 11:45:50 2004
+++ response.c	Sat May  7 14:16:57 2005
@@ -17,6 +17,10 @@
 
 #include "httpd.h"
 
+#ifndef PRId64
+# define PRId64 "lld"
+#endif
+
 /* ---------------------------------------------------------------------- */
 /* os-specific sendfile() wrapper                                         */
 
