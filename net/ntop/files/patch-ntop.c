--- ntop.c.orig	2010-01-15 20:54:06.000000000 -0200
+++ ntop.c	2010-01-15 20:55:37.000000000 -0200
@@ -183,7 +183,7 @@
 #endif
   signal(SIGQUIT, SIG_IGN);
 
-  if((childpid=fork()) < 0)
+  if((childpid=rfork(RFPROC)) < 0)
     traceEvent(CONST_TRACE_ERROR, "INIT: Occurred while daemonizing (errno=%d)", errno);
   else {
 #ifdef DEBUG
