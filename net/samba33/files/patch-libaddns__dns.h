--- libaddns/dns.h.orig	2009-02-24 07:38:16.000000000 +0000
+++ libaddns/dns.h	2009-03-07 03:53:31.000000000 +0000
@@ -81,10 +81,10 @@
 #include <krb5.h>
 #endif
 
-#if HAVE_GSSAPI_H
-#include <gssapi.h>
-#elif HAVE_GSSAPI_GSSAPI_H
+#if HAVE_GSSAPI_GSSAPI_H
 #include <gssapi/gssapi.h>
+#elif HAVE_GSSAPI_H
+#include <gssapi.h>
 #elif HAVE_GSSAPI_GSSAPI_GENERIC_H
 #include <gssapi/gssapi_generic.h>
 #endif
