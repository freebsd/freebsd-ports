Description: Fix the supervise(8) operation if fork(2) fails.
Origin: http://marc.info/?l=djbdns&m=126856288028988&w=2
Author: Matthew Dempsky <matthew@dempsky.org>
Last-Update: 2010-03-15

--- supervise.c.orig
+++ supervise.c
@@ -148,11 +148,12 @@
 	pidchange();
 	announce();
 	if (flagexit) return;
-	if (flagwant && flagwantup) trystart();
 	break;
       }
     }
 
+    if (flagwant && flagwantup && !pid) trystart();
+
     if (read(fdcontrol,&ch,1) == 1)
       switch(ch) {
 	case 'd':
