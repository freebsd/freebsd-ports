--- trend/vscan-trend.h.orig	Tue Sep 28 20:42:52 2004
+++ trend/vscan-trend.h	Mon May 30 15:33:12 2005
@@ -9,11 +9,11 @@
 /* default location of samba-style configuration file (needs Samba >= 2.2.4
  or Samba 3.0 */
 
-#define PARAMCONF "/etc/samba/vscan-trend.conf"
+#define PARAMCONF "/usr/local/etc/samba-vscan/vscan-trend.conf"
 
 /* Trophie stuff:
    socket name of Trophie daemon */
-#define TROPHIE_SOCKET_NAME      "/var/run/trophie"
+#define TROPHIE_SOCKET_NAME      "/var/run/trophie/trophie.sock"
 
 /* End Configuration Section */
 
