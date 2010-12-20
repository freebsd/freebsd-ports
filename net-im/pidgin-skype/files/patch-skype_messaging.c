--- ./skype_messaging.c.orig	2010-01-28 02:22:49.000000000 +0100
+++ ./skype_messaging.c	2010-12-20 02:20:23.000000000 +0100
@@ -176,7 +176,7 @@
 #ifdef __APPLE__
 	guint timeout = 0;
 #else
-#ifdef _WIN32
+#if _WIN32 || __FreeBSD__
 	guint timeout = 0;
 #else
 	gboolean condition_result;
@@ -223,6 +223,12 @@
 
 		if (timeout++ == 10000)
 #else
+#ifdef __FreeBSD__
+		usleep(1000);
+		g_static_mutex_lock2(&mutex);
+		
+		if (timeout++ == 10000)
+#else
 		
 		//wait for message for a maximum of 10 seconds
 		g_get_current_time(&endtime);
@@ -235,6 +241,7 @@
 		if(!condition_result)
 #endif
 #endif
+#endif
 		{
 			//we timed out while waiting
 			g_hash_table_remove(message_queue, &cur_message_num);
