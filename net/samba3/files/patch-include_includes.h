--- include/includes.h.orig	Wed Aug 23 18:16:38 2006
+++ include/includes.h	Fri Sep  8 00:12:44 2006
@@ -475,10 +475,10 @@
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
