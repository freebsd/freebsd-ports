--- lib/mosquitto_internal.h.orig	2018-09-25 15:27:43 UTC
+++ lib/mosquitto_internal.h
@@ -31,11 +31,7 @@ Contributors:
 #endif
 #include <stdlib.h>
 
-#if defined(WITH_THREADING) && !defined(WITH_BROKER)
-#  include <pthread.h>
-#else
-#  include <dummypthread.h>
-#endif
+#include <pthread.h>
 
 #ifdef WITH_SRV
 #  include <ares.h>
@@ -194,7 +190,7 @@ struct mosquitto {
 #endif
 	bool want_write;
 	bool want_connect;
-#if defined(WITH_THREADING) && !defined(WITH_BROKER)
+
 	pthread_mutex_t callback_mutex;
 	pthread_mutex_t log_callback_mutex;
 	pthread_mutex_t msgtime_mutex;
@@ -205,7 +201,7 @@ struct mosquitto {
 	pthread_mutex_t out_message_mutex;
 	pthread_mutex_t mid_mutex;
 	pthread_t thread_id;
-#endif
+
 	bool clean_session;
 #ifdef WITH_BROKER
 	char *old_id; /* for when a duplicate client connects, but we still want to
