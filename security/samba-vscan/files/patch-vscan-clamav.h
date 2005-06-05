--- clamav/vscan-clamav.h.orig	Wed Sep 29 20:36:09 2004
+++ clamav/vscan-clamav.h	Mon May 30 15:24:08 2005
@@ -9,11 +9,11 @@
 /* default location of samba-style configuration file (needs Samba >= 2.2.4
  or Samba 3.0 */
 
-#define PARAMCONF "/etc/samba/vscan-clamav.conf"
+#define PARAMCONF "/usr/local/etc/samba-vscan/vscan-clamav.conf"
 
 /* Clam AntiVirus (clamd) stuff:
    socket name of Clam daemon */
-#define VSCAN_CLAMD_SOCKET_NAME      "/var/run/clamd"
+#define VSCAN_CLAMD_SOCKET_NAME      "/var/run/clamav/clamd"
 
 /* Clam AntiVirus (libclamav) stuff:
    maximum number of files in archive */
