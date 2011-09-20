--- ./parse.c.orig	2001-03-16 09:14:21.000000000 +0100
+++ ./parse.c	2011-08-29 00:31:55.000000000 +0200
@@ -99,6 +99,9 @@
 #ifdef USE_LDAP
     declare ("ldap", S_ldap);
 #endif
+#ifdef USE_RADIUS
+    declare ("radius",S_radius);
+#endif
     declare("member", S_member);
     declare("message", S_message);
     declare("name", S_name);
@@ -178,6 +181,10 @@
     case S_ldap:
       return ("ldap");
 #endif
+#ifdef USE_RADIUS
+    case S_radius:
+      return ("radius");
+#endif
    case S_expires:
 	return ("expires");
     case S_after:
