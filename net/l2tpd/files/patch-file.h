
$FreeBSD$

--- file.h.orig	Fri Jan 11 17:54:44 2002
+++ file.h	Tue Oct 22 12:41:18 2002
@@ -45,8 +45,8 @@
 #define SENSE_ALLOW -1
 #define SENSE_DENY 0
 
-#define DEFAULT_AUTH_FILE "/etc/l2tp/l2tp-secrets"
-#define CONFIG_FILE "/etc/l2tp/l2tpd.conf"
+#define DEFAULT_AUTH_FILE (PREFIX "/etc/l2tpd/l2tp-secrets")
+#define CONFIG_FILE (PREFIX "/etc/l2tpd/l2tpd.conf")
 
 /* Definition of an LNS */
 struct lns {
