--- os.h.orig	2024-03-26 16:41:57.000000000 -0700
+++ os.h	2024-04-03 07:39:11.395526000 -0700
@@ -161,6 +161,6 @@
 /* Changing those you won't be able to attach to your old sessions
  * when changing those values in official tree don't forget to bump
  * MSG_VERSION */
-#define MAXTERMLEN	32
+#define MAXTERMLEN	63
 #define MAXLOGINLEN	256
 
