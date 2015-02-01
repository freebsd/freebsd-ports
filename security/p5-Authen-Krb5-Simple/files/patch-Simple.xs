--- Simple.xs.orig	2015-01-04 05:05:11.000000000 +0900
+++ Simple.xs	2015-01-04 05:06:06.000000000 +0900
@@ -75,7 +75,11 @@
     INPUT:
     int errcode;
     INIT:
+#ifdef HAVE_HEIMDAL
+    char* result = (char*)krb5_get_error_message(0, errcode);
+#else
     char* result = (char*)error_message(errcode);
+#endif
     CODE:
     RETVAL = result;
     OUTPUT:
