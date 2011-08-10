--- ./src/lib/event.c.orig	2011-06-20 10:57:14.000000000 -0400
+++ ./src/lib/event.c	2011-08-10 07:39:10.000000000 -0400
@@ -155,7 +155,7 @@
 {
 	fr_event_t *ev;
 
-	if (!el || !callback | !when || (when->tv_usec > USEC)) return 0;
+	if (!el || !callback | !when || (when->tv_usec >= USEC)) return 0;
 
 	if (ev_p && *ev_p) fr_event_delete(el, ev_p);
 
@@ -364,9 +364,11 @@
 				if (when.tv_sec > 0) {
 					when.tv_sec--;
 					when.tv_usec += USEC;
+				} else {
+					when.tv_sec = 0;
 				}
 				when.tv_usec -= el->now.tv_usec;
-				if (when.tv_usec > USEC) {
+				if (when.tv_usec >= USEC) {
 					when.tv_usec -= USEC;
 					when.tv_sec++;
 				}
