--- e-util/e-msgport.c.orig	Wed Jan 14 00:04:04 2004
+++ e-util/e-msgport.c	Sun Sep 19 14:01:25 2004
@@ -921,9 +921,13 @@
 void e_thread_put(EThread *e, EMsg *msg)
 {
 	pthread_t id;
+	pthread_attr_t attr;
 	EMsg *dmsg = NULL;
 
 	pthread_mutex_lock(&e->mutex);
+	pthread_attr_init(&attr);
+	/* Give us a 1 MB thread stack size. */
+	pthread_attr_setstacksize(&attr, 0x100000);
 
 	/* the caller forgot to tell us what to do, well, we can't do anything can we */
 	if (e->received == NULL) {
@@ -962,13 +966,14 @@
 		e_msgport_put(e->server_port, msg);
 		if (e->waiting == 0
 		    && g_list_length(e->id_list) < e->queue_limit
-		    && pthread_create(&id, NULL, thread_dispatch, e) == 0) {
+		    && pthread_create(&id, &attr, thread_dispatch, e) == 0) {
 			struct _thread_info *info = g_malloc0(sizeof(*info));
 			t(printf("created NEW thread %ld\n", id));
 			info->id = id;
 			info->busy = TRUE;
 			e->id_list = g_list_append(e->id_list, info);
 		}
+		pthread_attr_destroy(&attr);
 		pthread_mutex_unlock(&e->mutex);
 		return;
 	}
@@ -977,12 +982,13 @@
 	if (e->id == E_THREAD_NONE) {
 		int err;
 
-		if ((err = pthread_create(&e->id, NULL, thread_dispatch, e)) != 0) {
+		if ((err = pthread_create(&e->id, &attr, thread_dispatch, e)) != 0) {
 			g_warning("Could not create dispatcher thread, message queued?: %s", strerror(err));
 			e->id = E_THREAD_NONE;
 		}
 	}
 
+	pthread_attr_destroy(&attr);
 	pthread_mutex_unlock(&e->mutex);
 
 	if (dmsg) {
