--- src/bgpd/session.h.orig	2020-05-18 19:17:41 UTC
+++ src/bgpd/session.h
@@ -18,6 +18,7 @@
 
 #include <sys/types.h>
 #include <sys/socket.h>
+#include <sys/queue.h>
 #include <time.h>
 
 #define	MAX_BACKLOG			5
@@ -146,7 +147,8 @@ struct ctl_conn {
 	int			terminate;
 };
 
-TAILQ_HEAD(ctl_conns, ctl_conn)	ctl_conns;
+TAILQ_HEAD(ctl_conns, ctl_conn);
+extern struct ctl_conns ctl_conns;
 
 struct peer_stats {
 	unsigned long long	 msg_rcvd_open;
