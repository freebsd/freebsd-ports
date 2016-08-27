--- util.c.orig	2004-01-22 22:25:39 UTC
+++ util.c
@@ -59,7 +59,12 @@ char *ethercodes = ETHERCODES;
 u_char zero[6] = { 0, 0, 0, 0, 0, 0 };
 u_char allones[6] = { 0xff, 0xff, 0xff, 0xff, 0xff, 0xff };
 
+/* VRRP/CARP ethernet prefix */
+u_char vrrp_prefix[5] = { 0x00, 0x00, 0x5e, 0x00, 0x01 };
+
 int debug = 0;
+int vrrpflag = 0;
+int zeroflag = 0;
 int initializing = 1;			/* true if initializing */
 
 /* syslog() helper routine */
