--- src/scancel/scancel.c.orig	2020-03-26 21:44:05 UTC
+++ src/scancel/scancel.c
@@ -99,6 +99,7 @@ static	pthread_cond_t   num_active_threads_cond;
 static	pthread_mutex_t  max_delay_lock;
 static	uint32_t max_resp_time = 0;
 static	int request_count = 0;
+opt_t opt;
 
 int
 main (int argc, char **argv)
