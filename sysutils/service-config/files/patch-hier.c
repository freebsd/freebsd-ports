--- hier.c.orig	Fri Dec 10 09:39:48 2004
+++ hier.c	Fri Dec 10 09:39:55 2004
@@ -2,8 +2,10 @@
 
 void hier()
 {
+  /*
   h(auto_home,-1,-1,02755);
   d(auto_home,"bin",-1,-1,02755);
+  */
 
   c(auto_home,"bin","ipc-config",-1,-1,0755);
   c(auto_home,"bin","ipcx-config",-1,-1,0755);
