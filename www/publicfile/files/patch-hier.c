--- hier.c.orig	Tue Apr 20 11:26:00 2004
+++ hier.c	Tue Apr 20 11:26:06 2004
@@ -2,9 +2,9 @@
 
 void hier()
 {
-  h(auto_home,-1,-1,02755);
+  h(auto_home,-1,-1,0755);
 
-  d(auto_home,"bin",-1,-1,02755);
+  d(auto_home,"bin",-1,-1,0755);
 
   c(auto_home,"bin","configure",-1,-1,0755);
   c(auto_home,"bin","httpd",-1,-1,0755);
