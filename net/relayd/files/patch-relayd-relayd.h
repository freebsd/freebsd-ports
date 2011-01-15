--- relayd/relayd.h.orig	2011-01-15 00:27:09.022494663 +0100
+++ relayd/relayd.h	2011-01-15 00:47:37.743251059 +0100
@@ -19,11 +19,12 @@
  */
 
 #include <sys/tree.h>
+
+#include <sys/param.h>		/* MAXHOSTNAMELEN */
+#include <limits.h>
 #ifdef __FreeBSD__
-#include <sys/param.h>
 #include <sys/queue.h>
 #endif
-
 #include <imsg.h>
 
 #ifdef __FreeBSD__
@@ -299,7 +300,9 @@
 	HCE_ICMP_OK,
 	HCE_ICMP_READ_TIMEOUT,
 	HCE_ICMP_WRITE_TIMEOUT,
-	HCE_TCP_CONNECT_ERROR,
+	HCE_TCP_SOCKET_ERROR,
+	HCE_TCP_SOCKET_LIMIT,
+	HCE_TCP_SOCKET_OPTION,
 	HCE_TCP_CONNECT_FAIL,
 	HCE_TCP_CONNECT_TIMEOUT,
 	HCE_TCP_CONNECT_OK,
@@ -637,6 +640,13 @@
 	struct ctl_icmp_event	 sc_icmp_recv;
 	struct ctl_icmp_event	 sc_icmp6_send;
 	struct ctl_icmp_event	 sc_icmp6_recv;
+
+	/* Event and signal handlers */
+	struct event		 sc_evsigint;
+	struct event		 sc_evsigterm;
+	struct event		 sc_evsigchld;
+	struct event		 sc_evsighup;
+	struct event		 sc_evsigpipe;
 };
 
 #define RELAYD_OPT_VERBOSE		0x01
@@ -699,6 +709,7 @@
 	IMSG_CTL_NOTIFY,
 	IMSG_CTL_RDR_STATS,
 	IMSG_CTL_RELAY_STATS,
+	IMSG_CTL_LOG_VERBOSE,
 	IMSG_RDR_ENABLE,	/* notifies from pfe to hce */
 	IMSG_RDR_DISABLE,
 	IMSG_TABLE_ENABLE,
@@ -799,7 +810,6 @@
 int	 relay_cmp_af(struct sockaddr_storage *,
 		 struct sockaddr_storage *);
 
-
 RB_PROTOTYPE(proto_tree, protonode, se_nodes, relay_proto_cmp);
 SPLAY_PROTOTYPE(session_tree, rsession, se_nodes, relay_session_cmp);
 
@@ -867,6 +877,7 @@
 void		 imsg_event_add(struct imsgev *);
 int	 	 imsg_compose_event(struct imsgev *, u_int16_t, u_int32_t,
 		    pid_t, int, void *, u_int16_t);
+void		 socket_rlimit(int);
 
 /* carp.c */
 int	 carp_demote_init(char *, int);
@@ -898,6 +909,7 @@
 
 /* log.c */
 void	log_init(int);
+void	log_verbose(int);
 void	log_warn(const char *, ...);
 void	log_warnx(const char *, ...);
 void	log_info(const char *, ...);
