--- spool.c.orig	2016-02-07 12:41:49 UTC
+++ spool.c
@@ -416,7 +416,7 @@ flushqueue_since(unsigned int period)
 		return (0);
 
 	/* Did the flush file get touched within the last period seconds? */
-	if (st.st_mtim.tv_sec + period >= now.tv_sec)
+	if (st.st_mtim.tv_sec + (int)period >= now.tv_sec)
 		return (1);
 	else
 		return (0);
