--- hier.c.orig	Tue Apr 20 11:14:18 2004
+++ hier.c	Tue Apr 20 11:14:33 2004
@@ -2,13 +2,13 @@
 
 void hier()
 {
-  h(auto_home,-1,-1,02755);
+  h(auto_home,-1,-1,0755);
 
-  d(auto_home,"bin",-1,-1,02755);
-  d(auto_home,"doc",-1,-1,02755);
-  d(auto_home,"man",-1,-1,02755);
-  d(auto_home,"man/man1",-1,-1,02755);
-  d(auto_home,"man/cat1",-1,-1,02755);
+  d(auto_home,"bin",-1,-1,0755);
+  d(auto_home,"doc",-1,-1,0755);
+  d(auto_home,"man",-1,-1,0755);
+  d(auto_home,"man/man1",-1,-1,0755);
+  d(auto_home,"man/cat1",-1,-1,0755);
 
   c(auto_home,"doc","MATCHUP",-1,-1,0644);
   c(auto_home,"doc","ACCOUNTING",-1,-1,0644);
