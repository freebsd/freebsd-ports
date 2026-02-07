--- eventloop.c.orig	2016-02-10 18:38:43 UTC
+++ eventloop.c
@@ -38,7 +38,9 @@ struct pollcb { 
 static struct pollfd pollfds[MAX_POLLFD];
 static struct pollcb pollcbs[MAX_POLLFD];	
 
+#ifdef __Linux__
 static sigset_t event_sigs;
+#endif
 
 static int closeonexec(int fd)
 {
@@ -97,6 +99,7 @@ static void poll_callbacks(int n)
 }
 
 /* Run signal handler only directly after event loop */
+#ifdef __Linux__
 int event_signal(int sig)
 {
 	static int first = 1;
@@ -126,17 +129,25 @@ static int ppoll_fallback(struct pollfd 
 
 static int (*ppoll_vec)(struct pollfd *, nfds_t, const struct timespec
 			*, const sigset_t *);
+#endif
 
 void eventloop(void)
 {
+#ifdef __Linux__
 #if __GLIBC__ == 2 && __GLIBC_MINOR__ >= 5 || __GLIBC__ > 2
 	ppoll_vec = ppoll;
 #endif
 	if (!ppoll_vec) 
 		ppoll_vec = ppoll_fallback;
+#endif
 
 	for (;;) { 
+#ifdef __Linux__
 		int n = ppoll_vec(pollfds, max_pollfd, NULL, &event_sigs);
+#endif
+#ifdef __FreeBSD__
+		int n = poll(pollfds, max_pollfd, -1);
+#endif
 		if (n <= 0) {
 			if (n < 0 && errno != EINTR)
 				SYSERRprintf("poll error");
