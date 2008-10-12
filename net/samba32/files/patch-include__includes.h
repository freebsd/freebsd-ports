--- ./include/includes.h.orig	2008-09-18 06:49:02.000000000 +0000
+++ ./include/includes.h	2008-10-10 00:42:10.000000000 +0000
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
