--- Gui/mplayer/gtk/fs.h.orig	Fri Sep 28 19:48:50 2001
+++ Gui/mplayer/gtk/fs.h	Fri Sep 28 19:49:11 2001
@@ -9,7 +9,7 @@
 #include <glob.h>
 #include <unistd.h>
 
-#ifdef	__SVR4
+#if defined(__SVR4) || defined (__FreeBSD__)
 #define	get_current_dir_name()	getcwd(NULL, PATH_MAX)
 #endif
 
