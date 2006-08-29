--- server/netaux.c.orig	Tue Nov  1 07:08:56 1994
+++ server/netaux.c	Sun Aug 27 21:52:42 2006
@@ -20,6 +20,9 @@
 #else
 #include <sys/time.h>
 #endif
+#ifdef BSD_44
+#include <sys/resource.h>
+#endif
 
 /*
  * read_again -- (maybe) read in the active file again,
@@ -262,7 +265,11 @@
 reaper()
 {
 #ifndef USG
+#ifdef BSD_44
+	int status;
+#else
 	union wait	status;
+#endif
 
 	while (wait3(&status, WNOHANG, (struct rusage *)0) > 0)
 		;
