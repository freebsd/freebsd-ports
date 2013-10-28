--- core/stats.c.orig	2013-10-16 22:58:20.000000000 +0400
+++ core/stats.c	2013-10-28 21:19:30.000000000 +0400
@@ -440,6 +440,10 @@ void uwsgi_stats_pusher_loop(struct uwsg
 	void *events = event_queue_alloc(1);
 	for (;;) {
 		int nevents = event_queue_wait_multi(ut->queue, 1, events, 1);
+		if (nevents < 0) {
+			uwsgi_log_verbose("ending the stats pusher thread...\n");
+			return;
+		}
 		if (nevents > 0) {
 			int interesting_fd = event_queue_interesting_fd(events, 0);
 			char buf[4096];
