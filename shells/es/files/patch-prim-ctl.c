--- prim-ctl.c.orig	Sat Apr 12 04:54:34 1997
+++ prim-ctl.c	Sat Oct 12 23:33:16 2002
@@ -77,8 +77,10 @@
 				if (termeq(fromcatcher->term, "retry")) {
 					retry = TRUE;
 					unblocksignals();
-				} else
+				} else {
+					unblocksignals();
 					throw(fromcatcher);
+				}
 			EndExceptionHandler
 
 		EndExceptionHandler
