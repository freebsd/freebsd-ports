
$FreeBSD$

--- file.h.orig	Wed Apr 10 23:09:33 2002
+++ file.h	Wed Oct 23 16:34:37 2002
@@ -49,10 +49,10 @@
 #define SENSE_ALLOW -1
 #define SENSE_DENY 0
 
-#define DEFAULT_AUTH_FILE "/etc/l2tp/l2tp-secrets"
-#define ALT_DEFAULT_AUTH_FILE "/etc/l2tpd/l2tp-secrets"
-#define DEFAULT_CONFIG_FILE "/etc/l2tp/l2tpd.conf"
-#define ALT_DEFAULT_CONFIG_FILE "/etc/l2tpd/l2tpd.conf"
+#define DEFAULT_AUTH_FILE (PREFIX "/etc/l2tp/l2tp-secrets")
+#define ALT_DEFAULT_AUTH_FILE (PREFIX "/etc/l2tpd/l2tp-secrets")
+#define DEFAULT_CONFIG_FILE (PREFIX "/etc/l2tp/l2tpd.conf")
+#define ALT_DEFAULT_CONFIG_FILE (PREFIX "/etc/l2tpd/l2tpd.conf")
 #define DEFAULT_PID_FILE "/var/run/l2tpd.pid"
 
 /* Definition of an LNS */
