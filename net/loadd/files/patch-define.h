--- define.h.orig	Tue Oct  2 22:43:20 2001
+++ define.h	Tue May 14 14:45:36 2002
@@ -5,7 +5,7 @@
 #define MONITORINGPORT 8670 /* En UDP */
 #define PINGINTERVAL 60000000
 #define REFRESHTIMEOUT 1
-#define CONFFILE "/usr/local/etc/loadd2.conf"
+#define CONFFILE PREFIX "/etc/loadd.conf"
 #define CALC_CHECKSUM(acc, cksum) { \
         acc += cksum; \
         if (acc < 0) \
