--- ./include/includes.h.orig	Mon Apr  9 19:30:59 2007
+++ ./include/includes.h	Tue Apr 17 02:06:59 2007
@@ -209,10 +209,10 @@
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
