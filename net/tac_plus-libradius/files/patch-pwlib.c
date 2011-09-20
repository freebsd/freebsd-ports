--- ./pwlib.c.orig	2001-03-16 14:42:54.000000000 +0100
+++ ./pwlib.c	2011-08-29 00:31:55.000000000 +0200
@@ -40,6 +40,10 @@
 #include "ldap.h"
 #endif /* LDAP */
 
+#ifdef USE_RADIUS
+#include "radius.h"
+#endif
+
 /* Generic password verification routines for des, file and cleartext
    passwords */
 
@@ -177,6 +181,20 @@
         break; 
 #endif
 
+#ifdef USE_RADIUS
+	case (S_radius):
+	if (radius_verify(name,passwd,file)==1) {
+            data->status = TAC_PLUS_AUTHEN_STATUS_FAIL;
+            return (0);
+        } else {
+            data->status = TAC_PLUS_AUTHEN_STATUS_PASS;
+        }
+        exp_date = NULL;
+        set_expiration_status(exp_date, data);
+        return (data->status == TAC_PLUS_AUTHEN_STATUS_PASS);	 
+        break; 
+#endif
+
 
 #ifdef USE_PAM
         case (S_pam):
