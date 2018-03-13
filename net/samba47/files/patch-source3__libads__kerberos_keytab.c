--- source3/libads/kerberos_keytab.c.orig	2017-12-23 15:23:53 UTC
+++ source3/libads/kerberos_keytab.c
@@ -32,8 +32,6 @@
 
 #ifdef HAVE_KRB5
 
-#ifdef HAVE_ADS
-
 /* This MAX_NAME_LEN is a constant defined in krb5.h */
 #ifndef MAX_KEYTAB_NAME_LEN
 #define MAX_KEYTAB_NAME_LEN 1100
@@ -85,6 +83,8 @@
 	return ret;
 }
 
+#ifdef HAVE_ADS
+
 /**********************************************************************
  Adds a single service principal, i.e. 'host' to the system keytab
 ***********************************************************************/
