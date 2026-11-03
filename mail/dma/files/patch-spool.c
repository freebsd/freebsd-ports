--- spool.c.orig	2026-08-30 20:07:40 UTC
+++ spool.c
@@ -421,7 +421,7 @@ flushqueue_since(unsigned int period)
 		return (0);
 
 	/* Did the flush file get touched within the last period seconds? */
-	if (st.st_mtim.tv_sec + period >= now.tv_sec)
+	if (st.st_mtim.tv_sec + (int)period >= now.tv_sec)
 		return (1);
 	else
 		return (0);
