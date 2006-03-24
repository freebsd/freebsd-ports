--- ldap-nss.c.orig	Sat Mar 25 00:26:47 2006
+++ ldap-nss.c	Sat Mar 25 00:26:53 2006
@@ -68,7 +68,7 @@
 #endif
 
 /* Try to handle systems with both SASL libraries installed */
-#if defined(HAVE_SASL_SASL_H) && defined(HAVE_SASL_AUXPROP_REQUEST)
+#if defined(HAVE_SASL_SASL_H)
 #include <sasl/sasl.h>
 #elif defined(HAVE_SASL_H)
 #include <sasl.h>
