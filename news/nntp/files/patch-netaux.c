--- server/netaux.c.orig	Tue Jun  4 21:22:30 2002
+++ server/netaux.c	Tue Jun  4 21:23:10 2002
@@ -261,7 +261,7 @@
 
 reaper()
 {
-#ifndef USG
+#if !defined(USG) && !defined(BSD_44)
 	union wait	status;
 
 	while (wait3(&status, WNOHANG, (struct rusage *)0) > 0)
