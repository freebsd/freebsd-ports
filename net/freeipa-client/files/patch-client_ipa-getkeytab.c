--- client/ipa-getkeytab.c.orig	2023-08-21 14:29:00 UTC
+++ client/ipa-getkeytab.c
@@ -34,6 +34,13 @@
 #include <time.h>
 #include <krb5.h>
 #include <ldap.h>
+typedef unsigned char   u_char;
+typedef unsigned short  u_short;
+typedef unsigned int    u_int;
+typedef unsigned long   u_long;
+#include <sys/types.h>
+#include <netinet/in.h>
+#include <arpa/nameser.h>
 #include <resolv.h>
 #include <sasl/sasl.h>
 #include <popt.h>
