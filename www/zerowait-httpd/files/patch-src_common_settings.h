--- src/common/settings.h.orig	Sat Apr 16 06:48:58 2005
+++ src/common/settings.h	Wed Jun 22 13:35:16 2005
@@ -37,18 +37,18 @@
 #ifndef ROOT
 #define ROOT "/var/0W"
 #endif
-#define CONF ROOT "/conf"
-#define DATA ROOT "/data"
-#define CMD  ROOT "/cmd"
-#define LOGS ROOT "/logs"
-#define TMP  ROOT "/tmp"
+
+#define CONF ROOT "/etc/0W-httpd/"
+#define DATA ROOT "/0W-httpd"
+#define CMD     ROOT "/0W-httpd/cmd"
+#define LOGS ROOT "/0W-httpd/logs"
+#define TMP     ROOT "/0W-httpd/tmp"
 #define PIDS DATA "/pids"
 #define TMPL DATA "/templates"
-#define WWW  ROOT "/www"
-#define HTML WWW  "/data"
+#define WWW     ROOT "/0W-httpd"
+#define HTML ROOT  "/0W-httpd/data"
 
 #define RN "\r\n"
-
 
 #if __GLIBC__ == 2 && __GLIBC_MINOR__ >= 1
 #define HAVE_BACKTRACE
