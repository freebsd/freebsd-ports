Index: bgpd/session.c
===================================================================
RCS file: /home/cvs/private/hrs/openbgpd/bgpd/session.c,v
retrieving revision 1.1.1.1
retrieving revision 1.2
diff -u -p -r1.1.1.1 -r1.2
--- bgpd/session.c	30 Jun 2009 05:46:15 -0000	1.1.1.1
+++ bgpd/session.c	30 Jun 2009 06:40:07 -0000	1.2
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
