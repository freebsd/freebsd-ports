--- src/daemon.c.orig   2012-04-11 18:48:33 UTC
+++ src/daemon.c
@@ -97,7 +97,7 @@ int daemon_listen(DRIVER_CTX *DTX) {
   int domain = 0;		/* listening on domain socket? */
   int listener;			/* listener fd */
   int i;
-  int port = 24, queue = 32;	/* default port and queue size */
+  int port = 2424, queue = 32;	/* default port and queue size */
 
   signal(SIGPIPE, SIG_IGN);
   signal(SIGINT,  process_signal);
