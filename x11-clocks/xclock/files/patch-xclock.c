--- xclock.c.orig	2010-08-07 16:05:41.000000000 +0200
+++ xclock.c	2010-08-07 16:05:59.000000000 +0200
@@ -215,7 +215,7 @@ main(int argc, char *argv[])
 
 #ifdef HAVE_GETPID
     {
-	pid_t pid = getpid();
+	unsigned long pid = (unsigned long)getpid();
 	XChangeProperty(XtDisplay(toplevel), XtWindow(toplevel),
 			XInternAtom(XtDisplay(toplevel), "_NET_WM_PID", False),
 			XA_CARDINAL, 32, PropModeReplace,
