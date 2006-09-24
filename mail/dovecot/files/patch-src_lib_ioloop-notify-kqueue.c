--- src/lib/ioloop-notify-kqueue.c	16 Aug 2006 17:58:03 -0000	1.3.2.2
+++ src/lib/ioloop-notify-kqueue.c	26 Aug 2006 13:55:01 -0000	1.3.2.3
@@ -111,7 +111,10 @@
 	io->callback = callback;
 	io->context = context;
 
-	EV_SET(&ev, fd, EVFILT_VNODE, EV_ADD,
+	/* EV_CLEAR flag is needed because the EVFILT_VNODE filter reports
+	   event state transitions and not the current state.  With this flag,
+	   the same event is only returned once. */
+	EV_SET(&ev, fd, EVFILT_VNODE, EV_ADD | EV_CLEAR,
 	       NOTE_DELETE | NOTE_WRITE | NOTE_EXTEND | NOTE_REVOKE, 0, io);
 	if (kevent(ctx->kq, &ev, 1, NULL, 0, NULL) < 0) {
 		i_error("kevent(%d, %s) for notify failed: %m", fd, path);
