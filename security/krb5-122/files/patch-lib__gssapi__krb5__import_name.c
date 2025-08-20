--- lib/gssapi/krb5/import_name.c.orig	2025-08-05 14:15:15 UTC
+++ lib/gssapi/krb5/import_name.c
@@ -32,6 +32,11 @@
 #include <stdio.h>
 #endif
 
+#include <sys/param.h>
+#if __FreeBSD_version < 500100
+#include <stdio.h>
+#endif
+
 #ifdef HAVE_STRING_H
 #include <string.h>
 #else
