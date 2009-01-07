--- ./libaddns/dns.h.orig	2008-12-19 13:57:33.000000000 +0000
+++ ./libaddns/dns.h	2009-01-06 17:10:53.000000000 +0000
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
