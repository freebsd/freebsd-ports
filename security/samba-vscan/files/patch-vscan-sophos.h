--- sophos/vscan-sophos.h.old	Fri Aug 13 14:05:51 2004
+++ sophos/vscan-sophos.h	Fri Aug 13 14:07:07 2004
@@ -8,12 +8,12 @@
 
 /* Sophie stuff: 
    socket name of Sophie daemon */
-#define SOPHIE_SOCKET_NAME      "/var/run/sophie"
+#define SOPHIE_SOCKET_NAME      "/var/run/sophie/sophie.sock"
 
 /* default location of samba-style configuration file (needs Samba >= 2.2.4
  or Samba 3.0 */
 
-#define PARAMCONF "/etc/samba/vscan-sophos.conf"
+#define PARAMCONF "/usr/local/etc/samba-vscan/vscan-sophos.conf"
 
 
 /* False = log only infected file, True = log every file access */
