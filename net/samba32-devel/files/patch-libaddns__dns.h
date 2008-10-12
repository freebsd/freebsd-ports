--- ./libaddns/dns.h.orig	2008-10-10 00:47:19.000000000 +0000
+++ ./libaddns/dns.h	2008-10-10 00:47:57.000000000 +0000
@@ -81,12 +81,12 @@
 #include <krb5.h>
 #endif
 
-#if HAVE_GSSAPI_H
-#include <gssapi.h>
+#if HAVE_GSSAPI_GSSAPI_GENERIC_H
+#include <gssapi/gssapi_generic.h>
 #elif HAVE_GSSAPI_GSSAPI_H
 #include <gssapi/gssapi.h>
-#elif HAVE_GSSAPI_GSSAPI_GENERIC_H
-#include <gssapi/gssapi_generic.h>
+#elif HAVE_GSSAPI_H
+#include <gssapi.h>
 #endif
 
 #if defined(HAVE_GSSAPI_H) || defined(HAVE_GSSAPI_GSSAPI_H) || defined(HAVE_GSSAPI_GSSAPI_GENERIC_H)
