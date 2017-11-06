--- lib/gssapi/krb5/import_name.c.orig	Mon Jul 18 15:12:42 2005
+++ lib/gssapi/krb5/import_name.c	Tue Nov  8 09:53:58 2005
@@ -33,6 +33,11 @@
 #endif
 #endif
 
+#include <sys/param.h>
+#if __FreeBSD_version < 500100
+#include <stdio.h>
+#endif
+
 #ifdef HAVE_STRING_H
 #include <string.h>
 #else
