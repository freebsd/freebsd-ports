--- popen.c	Fri May 27 08:32:06 1994
+++ popen.c	Tue Jun  4 21:07:45 2002
@@ -55,7 +55,7 @@
 	int pid;
 	char done;
 	char free;
-	union wait status;
+	int status;
 	struct child *link;
 };
 static struct child *child;
@@ -320,11 +320,11 @@
 	int signo;
 {
 	int pid;
-	union wait status;
+	int status;
 	register struct child *cp;
 
 	while ((pid =
-	    wait3((int *)&status, WNOHANG, (struct rusage *)0)) > 0) {
+	    wait3(&status, WNOHANG, (struct rusage *)0)) > 0) {
 		cp = findchild(pid);
 		if (cp->free)
 			delchild(cp);
@@ -335,7 +335,7 @@
 	}
 }
 
-union wait wait_status;
+int wait_status;
 
 /*
  * Wait for a specific child to die.
@@ -352,7 +352,7 @@
 	wait_status = cp->status;
 	delchild(cp);
 	sigsetmask(mask);
-	return wait_status.w_status ? -1 : 0;
+	return wait_status ? -1 : 0;
 }
 
 /*
