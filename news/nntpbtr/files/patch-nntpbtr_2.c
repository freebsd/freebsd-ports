--- nntpbtr.c	Tue Jun  4 21:26:27 2002
+++ nntpbtr.c	Tue Jun  4 21:26:47 2002
@@ -95,7 +95,7 @@
 qchld()
 {
 	int pid;
-	union wait status;
+	int status;
 
 	while( (pid = wait3(&status, WNOHANG, (struct rusage *)0)) > 0 ) ;
 }
