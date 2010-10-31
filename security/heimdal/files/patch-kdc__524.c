--- kdc/524.c.orig	2010-10-15 14:18:24.000000000 +0200
+++ kdc/524.c	2010-10-15 14:19:43.000000000 +0200
@@ -33,6 +33,8 @@
 
 #include "kdc_locl.h"
 
+#ifdef KRB4
+
 #include <krb5-v4compat.h>
 
 /*
@@ -394,3 +396,4 @@
 	_kdc_free_ent (context, server);
     return ret;
 }
+#endif /* KRB4 */
