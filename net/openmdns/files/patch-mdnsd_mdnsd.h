--- mdnsd/mdnsd.h.orig	2017-03-10 09:24:12 UTC
+++ mdnsd/mdnsd.h
@@ -223,9 +223,12 @@ struct pge {
 };
 
 /* Publish Group Queue, should hold all publishing groups */
-TAILQ_HEAD(, pg)  pg_queue;
+typedef TAILQ_HEAD(, pg) pg_q;
+extern pg_q pg_queue;
+
 /* Publish Group Entry Queue, should hold all publishing group entries */
-TAILQ_HEAD(, pge) pge_queue;
+typedef TAILQ_HEAD(, pge) pge_q;
+extern pge_q pge_queue;
 
 struct kif {
 	char			ifname[IF_NAMESIZE];
@@ -397,7 +400,8 @@ int		 rr_send_an(struct rr *);
 void		 conflict_resolve_by_rr(struct rr *);
 
 /* control.c */
-TAILQ_HEAD(ctl_conns, ctl_conn) ctl_conns;
+typedef TAILQ_HEAD(ctl_conns, ctl_conn) ctl_conns_t;
+extern	ctl_conns_t ctl_conns;
 int     control_send_rr(struct ctl_conn *, struct rr *, int);
 int	control_send_ms(struct ctl_conn *, struct mdns_service *, int);
 int     control_try_answer_ms(struct ctl_conn *, char[MAXHOSTNAMELEN]);
