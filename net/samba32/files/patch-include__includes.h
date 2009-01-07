--- ./include/includes.h.orig	2008-12-19 13:57:33.000000000 +0000
+++ ./include/includes.h	2009-01-06 17:10:53.000000000 +0000
@@ -207,10 +207,10 @@
 #undef HAVE_LDAP
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
