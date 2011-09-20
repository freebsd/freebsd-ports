--- ./parse.h.orig	2001-03-16 09:18:44.000000000 +0100
+++ ./parse.h	2011-08-29 00:31:55.000000000 +0200
@@ -85,3 +85,6 @@
 #ifdef USE_LDAP
 #define S_ldap            46
 #endif /* LDAP */
+#ifdef USE_RADIUS
+#define S_radius	  47
+#endif /* radius */
