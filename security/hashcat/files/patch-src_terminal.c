--- src/terminal.c.orig	2022-09-02 14:58:13 UTC
+++ src/terminal.c
@@ -490,7 +490,7 @@ int tty_fix ()
 }
 #endif
 
-#if defined (__APPLE__) || defined (__FreeBSD__)
+#if defined (__APPLE__)
 static struct termios savemodes;
 static int havemodes = 0;
 
