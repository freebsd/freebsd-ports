--- run.c.orig	Sat Aug 21 02:46:33 1993
+++ run.c	Fri Jul 25 23:23:43 2003
@@ -94,18 +94,17 @@
 #include <stdio.h>
 #include <signal.h>
 #include <sys/wait.h>
-#include <varargs.h>
+#include <stdarg.h>
+#define MAXARGS 100
 
 static int dorun();
 
-int run (name,va_alist)
-char *name;
-va_dcl
+int run (char *name,...)
 {
 	int val;
 	va_list ap;
 
-	va_start(ap);
+	va_start(ap,name);
 	val = runv (name,ap);
 	va_end(ap);
 	return(val);
@@ -117,16 +116,18 @@
 	return (dorun (name, argv, 0));
 }
 
-int runp (name,va_alist)
-char *name;
-va_dcl
+int runp (char *name,...)
 {
 	int val;
 	va_list ap;
-
-	va_start(ap);
-	val = runvp (name,ap);
+	char *args[MAXARGS];
+	int argno=0;
+	
+	va_start(ap,name);
+        while (argno < MAXARGS 
+	       && (args[argno++] = va_arg(ap, char *)) != (char *)0);
 	va_end(ap);
+	val = runvp (name,args);
 	return (val);
 }
 
@@ -144,7 +145,7 @@
 	int wpid;
 	register int pid;
 	struct sigvec ignoresig,intsig,quitsig;
-	union wait status;
+	int status;
 	int execvp(), execv();
 	int (*execrtn)() = usepath ? execvp : execv;
 
@@ -165,7 +166,7 @@
 	sigvec (SIGINT,&ignoresig,&intsig);
 	sigvec (SIGQUIT,&ignoresig,&quitsig);
 	do {
-		wpid = wait3 (&status.w_status, WUNTRACED, 0);
+		wpid = wait3 (&status, WUNTRACED, 0);
 		if (WIFSTOPPED (status)) {
 		    kill (0,SIGTSTP);
 		    wpid = 0;
@@ -174,8 +175,8 @@
 	sigvec (SIGINT,&intsig,0);	/* restore signals */
 	sigvec (SIGQUIT,&quitsig,0);
 
-	if (WIFSIGNALED (status) || status.w_retcode == 0377)
+	if (WIFSIGNALED (status) || WEXITSTATUS(status) == 0377)
 		return (-1);
 
-	return (status.w_retcode);
+	return (WEXITSTATUS(status));
 }
