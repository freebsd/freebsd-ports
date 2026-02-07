--- src/common/settings.h.orig	2008-02-04 12:42:36.000000000 +0100
+++ src/common/settings.h	2008-09-26 18:59:48.000000000 +0200
@@ -40,15 +40,15 @@
 #ifndef ROOT
 #define ROOT "/var/0W"
 #endif
-#define CONF ROOT "/conf"
-#define DATA ROOT "/data"
-#define CMD  ROOT "/cmd"
-#define LOGS ROOT "/logs"
-#define TMP  ROOT "/tmp"
+#define CONF ROOT "/etc/0W-httpd/"
+#define DATA ROOT "/0W-httpd"
+#define CMD  ROOT "/0W-httpd/cmd"
+#define LOGS ROOT "/0W-httpd/logs"
+#define TMP  ROOT "/0W-httpd/tmp"
 #define PIDS DATA "/pids"
 #define TMPL DATA "/templates"
-#define WWW  ROOT "/www"
-#define HTML WWW  "/data"
+#define WWW  ROOT "/0W-httpd"
+#define HTML WWW  "/0W-httpd/data"
 
 #define RN "\r\n"
 
