--- hier.c.orig	Sat Apr 14 04:53:05 2001
+++ hier.c	Tue Sep 26 08:56:49 2006
@@ -2,19 +2,15 @@
 
 void hier()
 {
-  h(auto_home,-1,-1,02755);
-  d(auto_home,"bin",-1,-1,02755);
+  h(auto_home,-1,-1,0755);
+  d(auto_home,"bin",-1,-1,0755);
   c(auto_home,"bin","fwipe0",-1,-1,0755);
   c(auto_home,"bin","echo0",-1,-1,0755);
   c(auto_home,"bin","fwipe",-1,-1,0755);
 
-  d(auto_home,"man",-1,-1,02755);
-  d(auto_home,"man/man1",-1,-1,02755);
-  d(auto_home,"man/cat1",-1,-1,02755);
+  d(auto_home,"man",-1,-1,0755);
+  d(auto_home,"man/man1",-1,-1,0755);
   c(auto_home,"man/man1","fwipe0.1",-1,-1,0644);
-  c(auto_home,"man/cat1","fwipe0.0",-1,-1,0644);
   c(auto_home,"man/man1","echo0.1",-1,-1,0644);
-  c(auto_home,"man/cat1","echo0.0",-1,-1,0644);
   c(auto_home,"man/man1","fwipe.1",-1,-1,0644);
-  c(auto_home,"man/cat1","fwipe.0",-1,-1,0644);
 }
