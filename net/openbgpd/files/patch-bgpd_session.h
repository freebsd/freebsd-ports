Index: bgpd/session.h
===================================================================
RCS file: /home/cvs/private/hrs/openbgpd/bgpd/session.h,v
retrieving revision 1.1.1.7
retrieving revision 1.1.1.10
diff -u -p -r1.1.1.7 -r1.1.1.10
--- bgpd/session.h	14 Feb 2010 20:19:57 -0000	1.1.1.7
+++ bgpd/session.h	13 Oct 2012 18:22:50 -0000	1.1.1.10
@@ -1,4 +1,4 @@
-/*	$OpenBSD: session.h,v 1.101 2009/06/05 20:26:38 claudio Exp $ */
+/*	$OpenBSD: session.h,v 1.113 2012/04/12 17:26:09 claudio Exp $ */
 
 /*
  * Copyright (c) 2003, 2004 Henning Brauer <henning@openbsd.org>
@@ -94,6 +94,13 @@ enum suberr_open {
 	ERR_OPEN_CAPA
 };
 
+enum suberr_fsm {
+	ERR_FSM_UNSPECIFIC = 0,
+	ERR_FSM_UNEX_OPENSENT,
+	ERR_FSM_UNEX_OPENCONFIRM,
+	ERR_FSM_UNEX_ESTABLISHED
+};
+
 enum opt_params {
 	OPT_PARAM_NONE,
 	OPT_PARAM_AUTH,
@@ -109,7 +116,7 @@ enum capa_codes {
 };
 
 struct bgp_msg {
-	struct buf	*buf;
+	struct ibuf	*buf;
 	enum msg_type	 type;
 	u_int16_t	 len;
 };
@@ -155,8 +162,10 @@ struct peer_stats {
 	u_int64_t		 msg_sent_rrefresh;
 	u_int64_t		 prefix_rcvd_update;
 	u_int64_t		 prefix_rcvd_withdraw;
+	u_int64_t		 prefix_rcvd_eor;
 	u_int64_t		 prefix_sent_update;
 	u_int64_t		 prefix_sent_withdraw;
+	u_int64_t		 prefix_sent_eor;
 	time_t			 last_updown;
 	time_t			 last_read;
 	u_int32_t		 prefix_cnt;
@@ -172,6 +181,7 @@ enum Timer {
 	Timer_IdleHold,
 	Timer_IdleHoldReset,
 	Timer_CarpUndemote,
+	Timer_RestartTimeout,
 	Timer_Max
 };
 
@@ -189,6 +199,7 @@ struct peer {
 	struct {
 		struct capabilities	ann;
 		struct capabilities	peer;
+		struct capabilities	neg;
 	}			 capa;
 	struct {
 		struct bgpd_addr	local_addr;
@@ -201,7 +212,7 @@ struct peer {
 	struct sockaddr_storage	 sa_remote;
 	struct peer_timer_head	 timers;
 	struct msgbuf		 wbuf;
-	struct buf_read		*rbuf;
+	struct ibuf_read	*rbuf;
 	struct peer		*next;
 	int			 fd;
 	int			 lasterr;
@@ -217,47 +228,25 @@ struct peer {
 	u_int8_t		 passive;
 };
 
-struct peer	*peers;
+extern struct peer	*peers;
+extern time_t		 pauseaccept;
 
 struct ctl_timer {
 	enum Timer	type;
 	time_t		val;
 };
 
-/* session.c */
-void		 session_socket_blockmode(int, enum blockmodes);
-pid_t		 session_main(struct bgpd_config *, struct peer *,
-		    struct network_head *, struct filter_head *,
-		    struct mrt_head *, struct rib_names *,
-		    int[2], int[2], int[2], int[2]);
-void		 bgp_fsm(struct peer *, enum session_events);
-int		 session_neighbor_rrefresh(struct peer *p);
-struct peer	*getpeerbyaddr(struct bgpd_addr *);
-struct peer	*getpeerbydesc(const char *);
-int		 imsg_compose_parent(int, pid_t, void *, u_int16_t);
-int		 imsg_compose_rde(int, pid_t, void *, u_int16_t);
-
-/* log.c */
-char		*log_fmt_peer(const struct peer_config *);
-void		 log_statechange(struct peer *, enum session_state,
-		    enum session_events);
-void		 log_notification(const struct peer *, u_int8_t, u_int8_t,
-		    u_char *, u_int16_t);
-void		 log_conn_attempt(const struct peer *, struct sockaddr *);
-
-/* parse.y */
-int	 parse_config(char *, struct bgpd_config *, struct mrt_head *,
-	    struct peer **, struct network_head *, struct filter_head *);
+/* carp.c */
+int	 carp_demote_init(char *, int);
+void	 carp_demote_shutdown(void);
+int	 carp_demote_get(char *);
+int	 carp_demote_set(char *, int);
 
 /* config.c */
 int	 merge_config(struct bgpd_config *, struct bgpd_config *,
 	    struct peer *, struct listen_addrs *);
 void	 prepare_listeners(struct bgpd_config *);
-
-/* rde.c */
-pid_t	 rde_main(struct bgpd_config *, struct peer *, struct network_head *,
-	    struct filter_head *, struct mrt_head *, struct rib_names *,
-	    int[2], int[2], int[2], int[2], int);
+int	 get_mpe_label(struct rdomain *);
 
 /* control.c */
 int	control_init(int, char *);
@@ -266,7 +255,27 @@ void	control_shutdown(int);
 int	control_dispatch_msg(struct pollfd *, u_int *);
 unsigned int	control_accept(int, int);
 
+/* log.c */
+char		*log_fmt_peer(const struct peer_config *);
+void		 log_statechange(struct peer *, enum session_state,
+		    enum session_events);
+void		 log_notification(const struct peer *, u_int8_t, u_int8_t,
+		    u_char *, u_int16_t, const char *);
+void		 log_conn_attempt(const struct peer *, struct sockaddr *);
+
+/* mrt.c */
+void		 mrt_dump_bgp_msg(struct mrt *, void *, u_int16_t,
+		     struct peer *);
+void		 mrt_dump_state(struct mrt *, u_int16_t, u_int16_t,
+		     struct peer *);
+
+/* parse.y */
+int	 parse_config(char *, struct bgpd_config *, struct mrt_head *,
+	    struct peer **, struct network_head *, struct filter_head *,
+	    struct rdomain_head *);
+
 /* pfkey.c */
+int	pfkey_read(int, struct sadb_msg *);
 int	pfkey_establish(struct peer *);
 int	pfkey_remove(struct peer *);
 int	pfkey_init(struct bgpd_sysdep *);
@@ -274,15 +283,24 @@ int	pfkey_init(struct bgpd_sysdep *);
 /* printconf.c */
 void	print_config(struct bgpd_config *, struct rib_names *,
 	    struct network_head *, struct peer *, struct filter_head *,
-	    struct mrt_head *);
+	    struct mrt_head *, struct rdomain_head *);
 
-/* carp.c */
-int	 carp_demote_init(char *, int);
-void	 carp_demote_shutdown(void);
-int	 carp_demote_get(char *);
-int	 carp_demote_set(char *, int);
+/* rde.c */
+pid_t	 rde_main(int[2], int[2], int[2], int[2], int);
+
+/* session.c */
+void		 session_socket_blockmode(int, enum blockmodes);
+pid_t		 session_main(int[2], int[2], int[2], int[2]);
+void		 bgp_fsm(struct peer *, enum session_events);
+int		 session_neighbor_rrefresh(struct peer *p);
+struct peer	*getpeerbyaddr(struct bgpd_addr *);
+struct peer	*getpeerbydesc(const char *);
+int		 imsg_compose_parent(int, u_int32_t, pid_t, void *, u_int16_t);
+int		 imsg_compose_rde(int, pid_t, void *, u_int16_t);
+void	 	 session_stop(struct peer *, u_int8_t);
 
 /* timer.c */
+time_t			 getmonotime(void);
 struct peer_timer	*timer_get(struct peer *, enum Timer);
 struct peer_timer	*timer_nextisdue(struct peer *);
 time_t			 timer_nextduein(struct peer *);
