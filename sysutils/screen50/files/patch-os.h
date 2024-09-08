--- os.h.orig	2024-07-27 07:09:11.000000000 -0700
+++ os.h	2024-08-19 08:47:21.152670000 -0700
@@ -148,7 +148,7 @@
  */
 
 #ifndef TERMCAP_BUFSIZE
-# define TERMCAP_BUFSIZE 1023
+# define TERMCAP_BUFSIZE 1024
 #endif
 
 /*
@@ -161,6 +161,6 @@
 /* Changing those you won't be able to attach to your old sessions
  * when changing those values in official tree don't forget to bump
  * MSG_VERSION */
-#define MAXTERMLEN	32
+#define MAXTERMLEN	63
 #define MAXLOGINLEN	256
 
