--- openantivirus/vscan-oav.h.old	Fri Aug 13 14:04:07 2004
+++ openantivirus/vscan-oav.h	Fri Aug 13 14:04:23 2004
@@ -6,7 +6,7 @@
 /* default location of samba-style configuration file (needs Samba >= 2.2.4
  or Samba 3.0 */
 
-#define PARAMCONF "/etc/samba/vscan-oav.conf"
+#define PARAMCONF "/usr/local/etc/samba-vscan/vscan-oav.conf"
 
 
 /* False = log only infected file, True = log every file access */
