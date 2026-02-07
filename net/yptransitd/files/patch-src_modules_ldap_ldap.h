--- src/modules/ldap/ldap.h.orig	2001-10-03 00:59:53 UTC
+++ src/modules/ldap/ldap.h
@@ -42,6 +42,9 @@
 #define PWLINE "%s:%s:%s:%s:%s:%s:%s"
 #define PWLINE_SIZE 6
 
+#define MPWLINE "%s:%s:%s:%s::0:0:%s:%s:%s"
+#define MPWLINE_SIZE 11
+
 #define GWLINE "%s:%s:%s:%s"
 #define GWLINE_SIZE 3
 
