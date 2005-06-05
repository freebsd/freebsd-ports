--- sophos/vscan-sophos.h.orig	Tue Sep 28 20:42:51 2004
+++ sophos/vscan-sophos.h	Mon May 30 15:31:29 2005
@@ -9,11 +9,11 @@
 /* default location of samba-style configuration file (needs Samba >= 2.2.4
  or Samba 3.0 */
 
-#define PARAMCONF "/etc/samba/vscan-sophos.conf"
+#define PARAMCONF "/usr/local/etc/samba-vscan/vscan-sophos.conf"
 
 /* Sophie stuff:
    socket name of Sophie daemon */
-#define SOPHIE_SOCKET_NAME      "/var/run/sophie"
+#define SOPHIE_SOCKET_NAME      "/var/run/sophie/sophie.sock"
 
 /* End Configuration Section */
 
