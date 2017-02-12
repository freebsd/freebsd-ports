--- src/fdevent_freebsd_kqueue.c.orig	2017-02-11 19:44:05 UTC
+++ src/fdevent_freebsd_kqueue.c
@@ -75,14 +75,14 @@ static int fdevent_freebsd_kqueue_event_
 	if (events == oevents) return fd;
 
 	if (addevents & FDEVENT_IN)  {
-		EV_SET(&kev[n], fd, EVFILT_READ, EV_ADD|EV_CLEAR, 0, 0, NULL);
+		EV_SET(&kev[n], fd, EVFILT_READ, EV_ADD, 0, 0, NULL);
 		n++;
 	} else if (delevents & FDEVENT_IN) {
 		EV_SET(&kev[n], fd, EVFILT_READ, EV_DELETE, 0, 0, NULL);
 		n++;
 	}
 	if (addevents & FDEVENT_OUT)  {
-		EV_SET(&kev[n], fd, EVFILT_WRITE, EV_ADD|EV_CLEAR, 0, 0, NULL);
+		EV_SET(&kev[n], fd, EVFILT_WRITE, EV_ADD, 0, 0, NULL);
 		n++;
 	} else if (delevents & FDEVENT_OUT) {
 		EV_SET(&kev[n], fd, EVFILT_WRITE, EV_DELETE, 0, 0, NULL);
