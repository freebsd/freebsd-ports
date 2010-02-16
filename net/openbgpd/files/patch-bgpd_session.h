Index: bgpd/session.h
===================================================================
RCS file: /home/cvs/private/hrs/openbgpd/bgpd/session.h,v
retrieving revision 1.1.1.7
retrieving revision 1.1.1.8
diff -u -p -r1.1.1.7 -r1.1.1.8
--- bgpd/session.h	14 Feb 2010 20:19:57 -0000	1.1.1.7
+++ bgpd/session.h	14 Feb 2010 20:27:06 -0000	1.1.1.8
@@ -1,4 +1,4 @@
-/*	$OpenBSD: session.h,v 1.101 2009/06/05 20:26:38 claudio Exp $ */
+/*	$OpenBSD: session.h,v 1.104 2009/12/31 15:34:02 claudio Exp $ */
 
 /*
  * Copyright (c) 2003, 2004 Henning Brauer <henning@openbsd.org>
@@ -189,6 +189,7 @@ struct peer {
 	struct {
 		struct capabilities	ann;
 		struct capabilities	peer;
+		struct capabilities	neg;
 	}			 capa;
 	struct {
 		struct bgpd_addr	local_addr;
@@ -217,7 +218,7 @@ struct peer {
 	u_int8_t		 passive;
 };
 
-struct peer	*peers;
+extern struct peer	*peers;
 
 struct ctl_timer {
 	enum Timer	type;
@@ -226,16 +227,14 @@ struct ctl_timer {
 
 /* session.c */
 void		 session_socket_blockmode(int, enum blockmodes);
-pid_t		 session_main(struct bgpd_config *, struct peer *,
-		    struct network_head *, struct filter_head *,
-		    struct mrt_head *, struct rib_names *,
-		    int[2], int[2], int[2], int[2]);
+pid_t		 session_main(int[2], int[2], int[2], int[2], char *, char *);
 void		 bgp_fsm(struct peer *, enum session_events);
 int		 session_neighbor_rrefresh(struct peer *p);
 struct peer	*getpeerbyaddr(struct bgpd_addr *);
 struct peer	*getpeerbydesc(const char *);
 int		 imsg_compose_parent(int, pid_t, void *, u_int16_t);
 int		 imsg_compose_rde(int, pid_t, void *, u_int16_t);
+void	 	 session_stop(struct peer *, u_int8_t);
 
 /* log.c */
 char		*log_fmt_peer(const struct peer_config *);
@@ -255,9 +254,7 @@ int	 merge_config(struct bgpd_config *, 
 void	 prepare_listeners(struct bgpd_config *);
 
 /* rde.c */
-pid_t	 rde_main(struct bgpd_config *, struct peer *, struct network_head *,
-	    struct filter_head *, struct mrt_head *, struct rib_names *,
-	    int[2], int[2], int[2], int[2], int);
+pid_t	 rde_main(int[2], int[2], int[2], int[2], int);
 
 /* control.c */
 int	control_init(int, char *);
