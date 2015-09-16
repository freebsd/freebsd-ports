--- os.h.orig	2014-04-26 03:58:35.000000000 -0700
+++ os.h	2014-04-29 19:16:31.730773575 -0700
@@ -524,6 +528,6 @@
 /* Changing those you won't be able to attach to your old sessions
  * when changing those values in official tree don't forget to bump
  * MSG_VERSION */
-#define MAXTERMLEN	32
+#define MAXTERMLEN	63
 #define MAXLOGINLEN	256
 
