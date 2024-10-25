--- hier.c.orig	1999-11-09 07:23:46 UTC
+++ hier.c
@@ -2,9 +2,9 @@ void hier()
 
 void hier()
 {
-  h(auto_home,-1,-1,02755);
+  h(auto_home,-1,-1,0755);
 
-  d(auto_home,"bin",-1,-1,02755);
+  d(auto_home,"bin",-1,-1,0755);
 
   c(auto_home,"bin","configure",-1,-1,0755);
   c(auto_home,"bin","httpd",-1,-1,0755);
