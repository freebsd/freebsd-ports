--- hier.c	Tue May 22 20:26:57 2001
+++ hier.c	Tue May 22 20:27:32 2001
@@ -9,9 +9,6 @@
 
   d(auto_home,"man",-1,-1,02755);
   d(auto_home,"man/man1",-1,-1,02755);
-  d(auto_home,"man/cat1",-1,-1,02755);
   c(auto_home,"man/man1","safecat.1",-1,-1,0644);
-  c(auto_home,"man/cat1","safecat.0",-1,-1,0644);
   c(auto_home,"man/man1","maildir.1",-1,-1,0644);
-  c(auto_home,"man/cat1","maildir.0",-1,-1,0644);
 }
