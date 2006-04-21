--- ./talk/third_party/mediastreamer/mstimer.c.orig	Thu Mar 16 18:43:06 2006
+++ ./talk/third_party/mediastreamer/mstimer.c	Fri Apr 21 10:56:34 2006
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
 
