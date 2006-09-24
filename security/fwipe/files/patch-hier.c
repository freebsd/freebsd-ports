--- hier.c.orig	Fri Sep 22 07:11:47 2006
+++ hier.c	Fri Sep 22 07:12:15 2006
@@ -10,11 +10,7 @@
 
   d(auto_home,"man",-1,-1,02755);
   d(auto_home,"man/man1",-1,-1,02755);
-  d(auto_home,"man/cat1",-1,-1,02755);
   c(auto_home,"man/man1","fwipe0.1",-1,-1,0644);
-  c(auto_home,"man/cat1","fwipe0.0",-1,-1,0644);
   c(auto_home,"man/man1","echo0.1",-1,-1,0644);
-  c(auto_home,"man/cat1","echo0.0",-1,-1,0644);
   c(auto_home,"man/man1","fwipe.1",-1,-1,0644);
-  c(auto_home,"man/cat1","fwipe.0",-1,-1,0644);
 }
