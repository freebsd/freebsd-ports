--- src/include/prototypes.h.orig	Sun Feb 16 16:39:01 2003
+++ src/include/prototypes.h	Wed Nov 19 16:12:12 2003
@@ -270,7 +270,7 @@
 extern int no_debug;
 
 char   *strerror		(int);
-void	log			(const char *, ...)
+void	log_fg			(const char *, ...)
     __attribute__ ((format (printf, 1, 2)));
 void	debug			(int, const char *, ...)
     __attribute__ ((format (printf, 2, 3)));
