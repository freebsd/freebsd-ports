--- clamav/vscan-clamav.h.old	Fri Aug 13 13:42:37 2004
+++ clamav/vscan-clamav.h	Fri Aug 13 13:43:24 2004
@@ -7,7 +7,7 @@
 
 /* Clam AntiVirus (clamd) stuff: 
    socket name of Clam daemon */
-#define VSCAN_CLAMD_SOCKET_NAME      "/var/run/clamd"
+#define VSCAN_CLAMD_SOCKET_NAME      "/var/run/clamav/clamd"
 
 /* Clam AntiVirus (libclamav) stuff:
    maximum number of files in archive */
@@ -20,7 +20,7 @@
 /* default location of samba-style configuration file (needs Samba >= 2.2.4
  or Samba 3.0 */
 
-#define PARAMCONF "/etc/samba/vscan-clamav.conf"
+#define PARAMCONF "/usr/local/etc/samba-vscan/vscan-clamav.conf"
 
 
 /* False = log only infected file, True = log every file access */
