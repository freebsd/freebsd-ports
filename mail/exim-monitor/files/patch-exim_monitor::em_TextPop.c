--- exim_monitor/em_TextPop.c.orig	Tue Jun 18 11:47:45 2002
+++ exim_monitor/em_TextPop.c		Tue Jun 18 11:48:07 2002
@@ -71,8 +71,10 @@
 #include <X11/Xos.h>		/* for O_RDONLY */
 #include <errno.h>
 
+/*
 extern int errno, sys_nerr;
-/* extern char* sys_errlist[]; */
+extern char* sys_errlist[];
+*/
 
 #define DISMISS_NAME  ("cancel")
 #define DISMISS_NAME_LEN 6
