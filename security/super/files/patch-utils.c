--- utils.c.orig	Mon Jun 16 15:34:14 2003
+++ utils.c	Sun Jul 13 15:06:15 2003
@@ -1272,9 +1272,10 @@
 	if (add_variable("SI_SYSNAME", buf) == -1)
 	    return -1;
     }
-    return 0;
 #endif
 #endif
+
+    return 0;
 }
 
 #ifdef HAVE_UNAME
