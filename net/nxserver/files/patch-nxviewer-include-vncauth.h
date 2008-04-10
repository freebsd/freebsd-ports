--- nxviewer/include/vncauth.h.orig	Tue Oct 24 03:22:20 2006
+++ nxviewer/include/vncauth.h
@@ -42,6 +42,8 @@
 #define CHALLENGESIZE 16
 
 extern int vncEncryptAndStorePasswd(char *passwd, char *fname);
+extern int vncEncryptAndStorePasswd2(char *passwd, char *passwdViewOnly,
+    char *fname);
 extern char *vncDecryptPasswdFromFile(char *fname);
 extern void vncRandomBytes(unsigned char *bytes);
 extern void vncEncryptBytes(unsigned char *bytes, char *passwd);
