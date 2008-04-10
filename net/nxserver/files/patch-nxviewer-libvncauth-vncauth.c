--- nxviewer/libvncauth/vncauth.c.orig	Fri Dec  1 09:01:41 2006
+++ nxviewer/libvncauth/vncauth.c
@@ -140,6 +140,8 @@
 char *
 vncDecryptPasswdFromFile(char *fname)
 {
+    int vncDecryptPasswdFromFile2(char *fname,
+	char *passwdFullControl, char *passwdViewOnly);
     char *passwd;
 
     passwd = malloc(9);
