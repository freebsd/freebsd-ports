
$FreeBSD$

--- src/flow-cat.c.orig	Tue Aug 24 10:39:54 2004
+++ src/flow-cat.c	Tue Aug 24 10:40:09 2004
@@ -551,8 +551,8 @@
         break;
 
 next_file:
-
-    }  /* FOREACH filename in dir */
+	;
+    		}  /* FOREACH filename in dir */
 
   } /* foreach dir bundle */
 
