--- trend/vscan-trend.h.old	Fri Aug 13 14:12:27 2004
+++ trend/vscan-trend.h	Fri Aug 13 14:13:09 2004
@@ -8,12 +8,12 @@
 
 /* Trophie stuff: 
    socket name of Trophie daemon */
-#define TROPHIE_SOCKET_NAME      "/var/run/trophie"
+#define TROPHIE_SOCKET_NAME      "/var/run/trophie/trophie.sock"
 
 /* default location of samba-style configuration file (needs Samba >= 2.2.4
  or Samba 3.0 */
 
-#define PARAMCONF "/etc/samba/vscan-trend.conf"
+#define PARAMCONF "/usr/local/etc/samba-vscan/vscan-trend.conf"
 
 
 /* False = log only infected file, True = log every file access */
