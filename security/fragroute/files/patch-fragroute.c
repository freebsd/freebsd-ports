$NetBSD: patch-fragroute.c,v 1.1 2013/05/23 16:02:13 christos Exp $
In the unix case, don't use the obsolete libevent signal interface

--- fragroute.c.orig	2002-04-07 18:55:20.000000000 -0400
+++ fragroute.c	2013-05-23 11:59:52.000000000 -0400
@@ -36,10 +36,6 @@
 
 static struct fr_ctx 	 ctx;
 
-/* XXX - these should be in event.h */
-extern int		(*event_sigcb)(void);
-extern int		 event_gotsig;
-
 static void
 usage(void)
 {
@@ -136,6 +132,10 @@
 }
 
 #ifdef WIN32
+/* XXX - these should be in event.h */
+extern int		(*event_sigcb)(void);
+extern int		 event_gotsig;
+
 static BOOL CALLBACK
 fragroute_signal(DWORD sig)
 {
@@ -144,12 +144,25 @@
 	return (TRUE);
 }
 #else
+
 static void
-fragroute_signal(int sig)
+fragroute_signal(evutil_socket_t fd, short what, void *arg)
 {
+	int sig;
+	recv(fd, &sig, sizeof(sig), 0);
 	warnx("exiting on signal %d", sig);
-	event_gotsig++;
+	exit(sig);
 }
+
+static void
+addsignal(int sig) {
+	struct event sig_ev;
+	int got;
+
+	evsignal_set(&sig_ev, sig, fragroute_signal, &got);
+	evsignal_add(&sig_ev, NULL);
+}
+
 #endif
 
 static void
@@ -165,9 +178,6 @@
 		err(1, "couldn't initialize Winsock");
 
 	SetConsoleCtrlHandler(fragroute_signal, TRUE);
-#else
-	signal(SIGINT, fragroute_signal);
-	signal(SIGTERM, fragroute_signal);
 #endif
 	if (addr_aton(dst, &ctx.dst) < 0)
 		err(1, "destination address invalid");
@@ -178,7 +188,12 @@
 	pkt_init(128);
 	
 	event_init();
+#ifdef WIN32
 	event_sigcb = fragroute_close;
+#else
+	addsignal(SIGINT);
+	addsignal(SIGTERM);
+#endif
 	
 	if ((ctx.arp = arp_open()) == NULL ||
 	    (ctx.intf = intf_open()) == NULL ||
