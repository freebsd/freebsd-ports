--- mediastreamer2/mssync.c.orig	Sat Mar  4 06:07:01 2006
+++ mediastreamer2/mssync.c	Sat Mar 11 01:21:51 2006
@@ -194,6 +194,7 @@
 	MSSync *s=(MSSync*)arg;
 	uint64_t realtime;
 	uint64_t orig=get_cur_time();
+	int64_t diff;
 	s->ticks=1;
 	ms_mutex_lock(&s->lock);
 	while(s->run){
@@ -203,7 +204,7 @@
 		s->time+=s->interval;
 		while(1){
 			realtime=get_cur_time()-orig;
-			int64_t diff=s->time-realtime;
+			diff=s->time-realtime;
 			if (diff>0){
 				/* sleep until next tick */
 				sleepMs(diff);
