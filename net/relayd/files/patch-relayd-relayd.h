--- relayd/relayd.h.orig	2010-05-31 09:21:12.676718667 +0200
+++ relayd/relayd.h	2010-05-31 09:21:04.892410464 +0200
@@ -637,6 +637,13 @@
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
@@ -699,6 +706,7 @@
 	IMSG_CTL_NOTIFY,
 	IMSG_CTL_RDR_STATS,
 	IMSG_CTL_RELAY_STATS,
+	IMSG_CTL_LOG_VERBOSE,
 	IMSG_RDR_ENABLE,	/* notifies from pfe to hce */
 	IMSG_RDR_DISABLE,
 	IMSG_TABLE_ENABLE,
@@ -799,7 +807,6 @@
 int	 relay_cmp_af(struct sockaddr_storage *,
 		 struct sockaddr_storage *);
 
-
 RB_PROTOTYPE(proto_tree, protonode, se_nodes, relay_proto_cmp);
 SPLAY_PROTOTYPE(session_tree, rsession, se_nodes, relay_session_cmp);
 
@@ -894,6 +901,7 @@
 
 /* log.c */
 void	log_init(int);
+void	log_verbose(int);
 void	log_warn(const char *, ...);
 void	log_warnx(const char *, ...);
 void	log_info(const char *, ...);
