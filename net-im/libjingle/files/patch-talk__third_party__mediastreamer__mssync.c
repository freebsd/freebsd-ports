--- ./talk/third_party/mediastreamer/mssync.c.orig	Thu Mar 16 18:43:06 2006
+++ ./talk/third_party/mediastreamer/mssync.c	Fri Apr 21 10:56:34 2006
@@ -189,5 +189,6 @@
 	g_mutex_free(sync->lock);
 	g_cond_free(sync->thread_cond);
 	g_cond_free(sync->stop_cond);
+	return 0;
 }
 
