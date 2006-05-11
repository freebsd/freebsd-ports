--- ./talk/third_party/mediastreamer/mstimer.c.orig	Thu Mar 16 18:43:06 2006
+++ ./talk/third_party/mediastreamer/mstimer.c	Wed May 10 23:45:11 2006
@@ -33,8 +33,8 @@
 	ms_sync_init(MS_SYNC(sync));
 	MS_SYNC(sync)->attached_filters=sync->filters;
 	memset(sync->filters,0,MSTIMER_MAX_FILTERS*sizeof(MSFilter*));
-	MS_SYNC(sync)->samples_per_tick=160;
-	ms_timer_set_interval(sync,20);
+	MS_SYNC(sync)->samples_per_tick=80;
+	ms_timer_set_interval(sync,10);
 	sync->state=MS_TIMER_STOPPED;
 }
 
@@ -66,6 +66,8 @@
 	else {
 		gint32 diff,time;
 		struct timeval tv,cur;
+
+		timer->sync.time+=timer->milisec;
 	
 		gettimeofday(&cur,NULL);
 		time=((cur.tv_usec-timer->orig.tv_usec)/1000 ) + ((cur.tv_sec-timer->orig.tv_sec)*1000 );
@@ -74,14 +76,13 @@
 		}
 		while((diff = timer->sync.time-time) > 0)
 		{
-			tv.tv_sec = diff/1000;
-			tv.tv_usec = (diff%1000)*1000;
+			tv.tv_sec = timer->milisec/1000;
+			tv.tv_usec = (timer->milisec%1000)*1000;
 			select(0,NULL,NULL,NULL,&tv);
 			gettimeofday(&cur,NULL);
 			time=((cur.tv_usec-timer->orig.tv_usec)/1000 ) + ((cur.tv_sec-timer->orig.tv_sec)*1000 );
 		}
 	}
-	timer->sync.time+=timer->milisec;
 	return;
 }
 
