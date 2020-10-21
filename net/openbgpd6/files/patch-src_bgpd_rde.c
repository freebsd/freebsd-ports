--- src/bgpd/rde.c.orig	2020-05-04 14:45:09 UTC
+++ src/bgpd/rde.c
@@ -99,11 +99,9 @@ void		 rde_shutdown(void);
 int		 ovs_match(struct prefix *, u_int32_t);
 
 volatile sig_atomic_t	 rde_quit = 0;
-struct bgpd_config	*conf, *nconf;
+static struct bgpd_config	*conf, *nconf;
 struct filter_head	*out_rules, *out_rules_tmp;
-struct imsgbuf		*ibuf_se;
 struct imsgbuf		*ibuf_se_ctl;
-struct imsgbuf		*ibuf_main;
 struct rde_memstats	 rdemem;
 int			 softreconfig;
 
