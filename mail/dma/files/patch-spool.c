--- spool.c.orig	2013-06-03 14:03:15.000000000 +0000
+++ spool.c	2013-08-22 11:07:47.000000000 +0000
@@ -415,7 +415,7 @@ flushqueue_since(unsigned int period)
 		return (0);
 
 	/* Did the flush file get touched within the last period seconds? */
-	if (st.st_mtim.tv_sec + period >= now.tv_sec)
+	if (st.st_mtim.tv_sec + (int)period >= now.tv_sec)
 		return (1);
 	else
 		return (0);
