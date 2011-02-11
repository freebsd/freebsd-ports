--- ./ntop.c.orig	2011-02-02 10:23:03.000000000 +0100
+++ ./ntop.c	2011-02-02 10:24:12.000000000 +0100
@@ -187,7 +187,7 @@
 #endif
   signal(SIGQUIT, SIG_IGN);
 
-  if((childpid=fork()) < 0)
+  if((childpid=rfork(RFPROC)) < 0)
     traceEvent(CONST_TRACE_ERROR, "INIT: Occurred while daemonizing (errno=%d)", errno);
   else {
 #ifdef DEBUG
