--- hier.c	Mon Aug  6 23:27:18 2001
+++ hier.c	Mon Aug  6 23:27:45 2001
@@ -2,16 +2,13 @@
 
 void hier()
 {
-  h(auto_home,-1,-1,02755);
-  d(auto_home,"bin",-1,-1,02755);
+  h(auto_home,-1,-1,0755);
+  d(auto_home,"bin",-1,-1,0755);
   c(auto_home,"bin","safecat",-1,-1,0755);
   c(auto_home,"bin","maildir",-1,-1,0755);
 
-  d(auto_home,"man",-1,-1,02755);
-  d(auto_home,"man/man1",-1,-1,02755);
-  d(auto_home,"man/cat1",-1,-1,02755);
+  d(auto_home,"man",-1,-1,0755);
+  d(auto_home,"man/man1",-1,-1,0755);
   c(auto_home,"man/man1","safecat.1",-1,-1,0644);
-  c(auto_home,"man/cat1","safecat.0",-1,-1,0644);
   c(auto_home,"man/man1","maildir.1",-1,-1,0644);
-  c(auto_home,"man/cat1","maildir.0",-1,-1,0644);
 }
