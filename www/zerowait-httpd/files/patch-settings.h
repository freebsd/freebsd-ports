--- common/settings.h.orig	Thu Mar 17 20:22:31 2005
+++ common/settings.h	Thu Mar 17 20:25:53 2005
@@ -39,16 +39,16 @@
 #define BLOCK_SIZE	 4096
 #define BUFFER_SIZE	 4088
 
-#define ROOT "/var/0W"
-#define CONF ROOT "/conf"
-#define DATA ROOT "/data"
-#define CMD	 ROOT "/cmd"
-#define LOGS ROOT "/logs"
+#define ROOT "/var/0W/0W-httpd/"
+#define CONF ROOT "/var/0W/etc/0W-httpd/"
+#define DATA ROOT "/var/0W/0W-httpd/data"
+#define CMD	 ROOT "/var/0W/0W-httpd/cmd"
+#define LOGS ROOT "/var/0W/0W-httpd/logs/"
 #define TMP	 ROOT "/tmp"
-#define PIDS DATA "/pids"
-#define TMPL DATA "/templates"
-#define WWW	 ROOT "/www"
-#define HTML WWW  "/data"
+#define PIDS DATA "/var/0W/0W-httpd/pids"
+#define TMPL DATA "/var/0W/0W-httpd/templates"
+#define WWW	 ROOT "/var/0W/0W-httpd/www"
+#define HTML WWW  "/var/0W/0W-httpd/data"
 
 #define ADMIN_EMAIL "counter@rax.ru"
 #define SITE_URL "http://www.rax.ru"
