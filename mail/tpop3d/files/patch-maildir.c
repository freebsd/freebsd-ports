--- maildir.c.orig	Tue Nov 25 01:23:20 2003
+++ maildir.c	Sun Apr  3 09:44:25 2005
@@ -205,7 +205,7 @@
     mailbox M, failM = NULL;
     struct timeval tv1, tv2;
     float f;
-    int locked;
+    int locked = 0;
  
     alloc_struct(_mailbox, M);
     
