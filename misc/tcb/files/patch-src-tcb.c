--- src/tcb.c.orig	Mon Nov 23 15:51:15 1998
+++ src/tcb.c	Sun Nov 24 15:38:49 2002
@@ -12,7 +12,7 @@
 #include <sys/vt.h>
 #include <sys/kd.h>
 #else
-#include      <machine/console.h>
+#include      <sys/consio.h>
 #endif linux
 
 static struct {
@@ -574,7 +574,7 @@
 void sig_child(int dummy)
 {
   int pid;
-  union wait status;
+  int status;
 
   while ((pid = wait3((int*)&status, WNOHANG, (struct rusage *)0)) > 0) ;
 }
