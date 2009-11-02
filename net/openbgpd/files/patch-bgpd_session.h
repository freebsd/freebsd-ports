Index: bgpd/session.h
===================================================================
RCS file: /home/cvs/private/hrs/openbgpd/bgpd/session.h,v
retrieving revision 1.1.1.1
retrieving revision 1.1.1.3
diff -u -p -r1.1.1.1 -r1.1.1.3
--- bgpd/session.h	30 Jun 2009 05:46:15 -0000	1.1.1.1
+++ bgpd/session.h	22 Oct 2009 14:24:02 -0000	1.1.1.3
@@ -1,4 +1,4 @@
-/*	$OpenBSD: session.h,v 1.98 2008/05/08 09:53:12 henning Exp $ */
+/*	$OpenBSD: session.h,v 1.101 2009/06/05 20:26:38 claudio Exp $ */
 
 /*
  * Copyright (c) 2003, 2004 Henning Brauer <henning@openbsd.org>
@@ -171,6 +171,7 @@ enum Timer {
 	Timer_Hold,
 	Timer_IdleHold,
 	Timer_IdleHoldReset,
+	Timer_CarpUndemote,
 	Timer_Max
 };
 
@@ -227,13 +228,15 @@ struct ctl_timer {
 void		 session_socket_blockmode(int, enum blockmodes);
 pid_t		 session_main(struct bgpd_config *, struct peer *,
 		    struct network_head *, struct filter_head *,
-		    struct mrt_head *, int[2], int[2], int[2], int[2]);
+		    struct mrt_head *, struct rib_names *,
+		    int[2], int[2], int[2], int[2]);
 void		 bgp_fsm(struct peer *, enum session_events);
 int		 session_neighbor_rrefresh(struct peer *p);
 struct peer	*getpeerbyaddr(struct bgpd_addr *);
 struct peer	*getpeerbydesc(const char *);
 int		 imsg_compose_parent(int, pid_t, void *, u_int16_t);
 int		 imsg_compose_rde(int, pid_t, void *, u_int16_t);
+void	 	 session_stop(struct peer *, u_int8_t);
 
 /* log.c */
 char		*log_fmt_peer(const struct peer_config *);
@@ -254,8 +257,8 @@ void	 prepare_listeners(struct bgpd_conf
 
 /* rde.c */
 pid_t	 rde_main(struct bgpd_config *, struct peer *, struct network_head *,
-	    struct filter_head *, struct mrt_head *, int[2], int[2], int[2],
-	    int[2], int);
+	    struct filter_head *, struct mrt_head *, struct rib_names *,
+	    int[2], int[2], int[2], int[2], int);
 
 /* control.c */
 int	control_init(int, char *);
@@ -270,8 +273,9 @@ int	pfkey_remove(struct peer *);
 int	pfkey_init(struct bgpd_sysdep *);
 
 /* printconf.c */
-void	print_config(struct bgpd_config *, struct network_head *, struct peer *,
-	    struct filter_head *, struct mrt_head *);
+void	print_config(struct bgpd_config *, struct rib_names *,
+	    struct network_head *, struct peer *, struct filter_head *,
+	    struct mrt_head *);
 
 /* carp.c */
 int	 carp_demote_init(char *, int);
