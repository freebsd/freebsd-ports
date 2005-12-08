--- src/freebsd.c.orig	Fri Dec  9 16:24:52 2005
+++ src/freebsd.c	Fri Dec  9 16:25:12 2005
@@ -741,9 +741,9 @@
 	return out;
 }
 
+#endif
+
 /* empty stub so conky links */
 void free_all_processes( void )
 {
 }
-	
-#endif
