--- src/vcal_folder.c.orig	Mon May  8 06:44:25 2006
+++ src/vcal_folder.c	Wed May 10 13:34:17 2006
@@ -896,13 +896,22 @@
 static void url_read(const char *url, gboolean verbose, 
 	void (*callback)(const gchar *url, gchar *data, gboolean verbose))
 {
-	gchar *result = NULL;
-	thread_data *td = g_new0(thread_data, 1);
+	gchar *result;
+	thread_data *td;
+#ifdef USE_PTHREAD
 	pthread_t pt;
-	gchar *msg = NULL;
-	void *res = NULL;
-	time_t start_time = time(NULL);
-	gboolean killed = FALSE;
+#endif
+	gchar *msg;
+	void *res;
+	time_t start_time;
+	gboolean killed;
+
+	result = NULL;
+	td = g_new0(thread_data, 1);
+	msg = NULL;
+	res = NULL;
+	start_time = time(NULL);
+	killed = FALSE;
 	
 	td->url  = url;
 	td->result  = NULL;
