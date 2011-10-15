--- ./eventloop.c.orig	2009-12-15 07:18:40.000000000 -0500
+++ ./eventloop.c	2011-10-14 22:36:47.000000000 -0400
@@ -38,7 +38,9 @@
 static struct pollfd pollfds[MAX_POLLFD];
 static struct pollcb pollcbs[MAX_POLLFD];	
 
+#ifdef __Linux__
 static sigset_t event_sigs;
+#endif
 
 static int closeonexec(int fd)
 {
@@ -97,6 +99,7 @@
 }
 
 /* Run signal handler only directly after event loop */
+#ifdef __Linux__
 int event_signal(int sig)
 {
 	static int first = 1;
@@ -111,11 +114,17 @@
 		return -1;
 	return 0;
 }
+#endif
 
 void eventloop(void)
 {
 	for (;;) { 
+#ifdef __Linux__
 		int n = ppoll(pollfds, max_pollfd, NULL, &event_sigs);
+#endif
+#ifdef __FreeBSD__
+		int n = poll(pollfds, max_pollfd, -1);
+#endif
 		if (n <= 0) {
 			if (n < 0 && errno != EINTR)
 				SYSERRprintf("poll error");
