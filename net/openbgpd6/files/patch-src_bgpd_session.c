--- src/bgpd/session.c.orig	2020-05-19 09:24:33 UTC
+++ src/bgpd/session.c
@@ -100,13 +100,13 @@ void		 session_template_clone(struct peer *, struct so
 		    u_int32_t, u_int32_t);
 int		 session_match_mask(struct peer *, struct bgpd_addr *);
 
-struct bgpd_config	*conf, *nconf;
+static struct bgpd_config	*conf, *nconf;
+struct ctl_conns ctl_conns;
 struct bgpd_sysdep	 sysdep;
 volatile sig_atomic_t	 session_quit;
 int			 pending_reconf;
 int			 csock = -1, rcsock = -1;
 u_int			 peer_cnt;
-struct imsgbuf		*ibuf_rde;
 struct imsgbuf		*ibuf_rde_ctl;
 struct imsgbuf		*ibuf_main;
 
