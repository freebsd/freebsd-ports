--- src/lib/event.c	2014-12-17 13:49:16.000000000 -0800
+++ src/lib/event.c	2015-01-07 10:06:46.000000000 -0800
@@ -630,9 +630,9 @@ 
 		 *	Loop over all of the events, servicing them.
 		 */
 		for (i = 0; i < rcode; i++) {
-			if (el->events[i].flags & EV_EOF) {
-				fr_event_fd_t *ef = el->events[i].udata;
+			fr_event_fd_t *ef = el->events[i].udata;
 
+			if (el->events[i].flags & EV_EOF) {
 				/*
 				 *	FIXME: delete the handler
 				 *	here, and fix process.c to not
@@ -646,14 +646,12 @@ 
 				continue;
 			}
 
-			if (el->events[i].flags & EVFILT_READ) {
-				fr_event_fd_t *ef = el->events[i].udata;
-
-				ef->handler(el, ef->fd, ef->ctx);
-				continue;
-			}
-
-			/* else it's an unhandled event, which shouldn't happen */
+			/*
+			 *	Else it's our event.  We only set
+			 *	EVFILT_READ, so it must be a read
+			 *	event.
+			 */
+			ef->handler(el, ef->fd, ef->ctx);
 		}
 #endif	/* HAVE_KQUEUE */
 	}
