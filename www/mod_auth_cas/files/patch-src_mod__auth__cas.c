--- src/mod_auth_cas.c.orig	2016-12-10 12:15:10 UTC
+++ src/mod_auth_cas.c
@@ -22,7 +22,9 @@
  *
  */
 
+#ifdef HAVE_ERROR_H
 #include <error.h>
+#endif
 #include <string.h>
 #include <sys/file.h>
 #include <sys/types.h>
