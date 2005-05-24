--- hier.c.orig	Sun Feb 29 03:21:15 2004
+++ hier.c	Tue May 24 23:42:06 2005
@@ -4,8 +4,5 @@
 
 void hier()
 {
-  h(auto_home,-1,-1,02755);
-  d(auto_home,"bin",-1,-1,02755);
-
   c(auto_home,"bin","tinysu",auto_uid,auto_gid,04750);
 }
