--- f-secure/vscan-fsav.h.orig	Wed Sep 29 20:36:09 2004
+++ f-secure/vscan-fsav.h	Mon May 30 15:28:24 2005
@@ -40,7 +40,7 @@
 
 /* default location of samba-style configuration file (needs Samba >= 2.2.4 or Samba 3.0 */
 
-#define PARAMCONF "/etc/samba/vscan-fsav.conf"
+#define PARAMCONF "/usr/local/etc/samba-vscan/vscan-fsav.conf"
 
 /* FSAV-related settings */
 
@@ -52,13 +52,13 @@
 #define VSCAN_FSAV_CONNECT_ID 0
 
 /* fsav configuration file */
-#define VSCAN_FSAV_CONFIG_FILE "/etc/fsav.conf"
+#define VSCAN_FSAV_CONFIG_FILE "/usr/local/etc/fsav.conf"
 
 /* location of fsavd binary */
-#define VSCAN_FSAV_BINARY "/opt/f-secure/fsav/bin/fsavd"
+#define VSCAN_FSAV_BINARY "/usr/local/bin/fsavd"
 
 /* path to FSAV databases */
-#define VSCAN_FSAV_DB_DIR "/var/opt/f-secure/fsav/databases"
+#define VSCAN_FSAV_DB_DIR "/var/db/fsav/databases"
 
 /* fsav socket name */
 #define VSCAN_FSAV_SOCKET "/tmp/.fsav-0"
