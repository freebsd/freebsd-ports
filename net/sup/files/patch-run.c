--- run.c.orig	Fri Aug 20 20:46:33 1993
+++ run.c	Fri Oct 25 10:23:26 2002
@@ -95,6 +95,7 @@
 #include <signal.h>
 #include <sys/wait.h>
 #include <varargs.h>
+#define MAXARGS 100
 
 static int dorun();
 
@@ -123,10 +124,14 @@
 {
 	int val;
 	va_list ap;
-
+	char *args[MAXARGS];
+	int argno=0;
+	
 	va_start(ap);
-	val = runvp (name,ap);
+        while (argno < MAXARGS 
+	       && (args[argno++] = va_arg(ap, char *)) != (char *)0);
 	va_end(ap);
+	val = runvp (name,args);
 	return (val);
 }
 
@@ -144,7 +149,7 @@
 	int wpid;
 	register int pid;
 	struct sigvec ignoresig,intsig,quitsig;
-	union wait status;
+	int status;
 	int execvp(), execv();
 	int (*execrtn)() = usepath ? execvp : execv;
 
@@ -165,7 +170,7 @@
 	sigvec (SIGINT,&ignoresig,&intsig);
 	sigvec (SIGQUIT,&ignoresig,&quitsig);
 	do {
-		wpid = wait3 (&status.w_status, WUNTRACED, 0);
+		wpid = wait3 (&status, WUNTRACED, 0);
 		if (WIFSTOPPED (status)) {
 		    kill (0,SIGTSTP);
 		    wpid = 0;
@@ -174,8 +179,8 @@
 	sigvec (SIGINT,&intsig,0);	/* restore signals */
 	sigvec (SIGQUIT,&quitsig,0);
 
-	if (WIFSIGNALED (status) || status.w_retcode == 0377)
+	if (WIFSIGNALED (status) || WEXITSTATUS(status) == 0377)
 		return (-1);
 
-	return (status.w_retcode);
+	return (WEXITSTATUS(status));
 }
