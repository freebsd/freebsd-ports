--- src/configfile.c.orig	Thu Apr 26 01:50:01 2001
+++ src/configfile.c	Thu Apr 26 01:50:20 2001
@@ -45,7 +45,7 @@
 #define S_IWUSR  00200
 #endif
 
-#define GLOBAL_FINGERCONF "/etc/fingerconf"
+#define GLOBAL_FINGERCONF "%%PREfiX%%/etc/fingerconf"
 
 char *configfile = GLOBAL_FINGERCONF;
 Node * readconfig(char *filename);
