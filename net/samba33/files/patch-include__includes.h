--- ./include/includes.h.orig	2009-02-24 07:38:16.000000000 +0000
+++ ./include/includes.h	2009-03-07 03:42:32.000000000 +0000
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
@@ -870,7 +870,7 @@
 #endif
 
 #ifndef SIGRTMIN
-#define SIGRTMIN 32
+#define SIGRTMIN NSIG
 #endif
 
 #ifndef MAP_FILE
