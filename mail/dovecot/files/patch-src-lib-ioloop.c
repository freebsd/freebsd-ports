--- src/lib/ioloop.c.orig	2024-08-31 16:00:42.168389000 +0200
+++ src/lib/ioloop.c	2024-08-31 16:04:14.978513000 +0200
@@ -18,6 +18,7 @@
    Dovecot generally doesn't have very important short timeouts, so to avoid
    logging many warnings about this, use a rather high value. */
 #define IOLOOP_TIME_MOVED_FORWARDS_MIN_USECS (100000)
+#define IOLOOP_TIME_MOVED_FORWARDS_MIN_USECS_LARGE (1000000)
 
 time_t ioloop_time = 0;
 struct timeval ioloop_timeval;
@@ -654,9 +655,13 @@
 		/* the callback may have slept, so check the time again. */
 		i_gettimeofday(&ioloop_timeval);
 	} else {
+		int max_diff = diff_usecs < IOLOOP_TIME_MOVED_FORWARDS_MIN_USECS_LARGE ?
+			IOLOOP_TIME_MOVED_FORWARDS_MIN_USECS :
+			IOLOOP_TIME_MOVED_FORWARDS_MIN_USECS_LARGE;
+
 		diff_usecs = timeval_diff_usecs(&ioloop->next_max_time,
 						&ioloop_timeval);
-		if (unlikely(-diff_usecs >= IOLOOP_TIME_MOVED_FORWARDS_MIN_USECS)) {
+		if (unlikely(-diff_usecs >= max_diff)) {
 			io_loops_timeouts_update(-diff_usecs);
 			/* time moved forwards */
 			ioloop->time_moved_callback(&ioloop->next_max_time,
