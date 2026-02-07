--- src/kerberospw.h.orig	2015-03-29 03:42:28 UTC
+++ src/kerberospw.h
@@ -15,8 +15,8 @@
  *
  **/
 
+#include <krb5.h>
 #include <gssapi/gssapi.h>
-#include <gssapi/gssapi_generic.h>
 #include <gssapi/gssapi_krb5.h>
 
 #define krb5_get_err_text(context,code) error_message(code)
