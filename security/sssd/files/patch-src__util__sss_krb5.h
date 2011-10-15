--- ./src/util/sss_krb5.h.orig	2011-08-29 11:39:05.000000000 -0400
+++ ./src/util/sss_krb5.h	2011-10-13 12:15:09.000000000 -0400
@@ -34,6 +34,8 @@
 
 #include "util/util.h"
 
+#define KRB5_CALLCONV
+
 const char * KRB5_CALLCONV sss_krb5_get_error_message (krb5_context,
                                                    krb5_error_code);
 
