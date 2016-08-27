--- util.h.orig	1996-10-06 10:22:14 UTC
+++ util.h
@@ -14,6 +14,9 @@ extern char *ethercodes;
 
 extern u_char zero[6];
 extern u_char allones[6];
+extern u_char vrrp_prefix[5];
 
 extern int debug;
+extern int vrrpflag;
+extern int zeroflag;
 extern int initializing;
