
$FreeBSD$

--- src/flow-receive.c.orig	Tue Aug 24 10:41:43 2004
+++ src/flow-receive.c	Tue Aug 24 10:41:55 2004
@@ -733,8 +733,8 @@
       } /* for */
 
 skip1:
-
-    } /* if FD_ISSET */
+	;
+    	} /* if FD_ISSET */
 
   } /* while 1 */
 
