--- bgpd/session.c	2008-03-18 15:24:06.000000000 +0100
+++ bgpd/session.c	2008-03-18 13:27:29.000000000 +0100
@@ -52,6 +52,10 @@
 #define PFD_SOCK_RCTL		4
 #define PFD_LISTENERS_START	5
 
+#if defined(__FreeBSD__) /* FreeBSD has no LINK_STATE_IS_UP macro. */
+#define LINK_STATE_IS_UP(_s)  ((_s) >= LINK_STATE_UP)
+#endif /* defined(__FreeBSD__) */ 
+
 void	session_sighdlr(int);
 int	setup_listeners(u_int *);
 void	init_conf(struct bgpd_config *);
