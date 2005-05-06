--- ../ifstated-20050505.orig/ifstated.h	Thu May  5 11:51:24 2005
+++ ifstated.h	Thu Nov 18 16:48:39 2004
@@ -1,4 +1,5 @@
 /*	$OpenBSD: ifstated.h,v 1.4 2004/03/10 00:13:38 deraadt Exp $	*/
+/*	$Id: ifstated.h,v 1.2 2004/11/18 21:48:39 mdg Exp $	*/

 /*
  * Copyright (c) 2004 Ryan McBride
@@ -47,7 +48,7 @@

 struct ifsd_external {
 	TAILQ_ENTRY(ifsd_external)	 entries;
-	struct event			 ev;
+	struct kevent			 kev;
 	struct ifsd_expression_list	 expressions;
 	char				*command;
 	int				 prevstatus;
@@ -107,7 +108,7 @@
 TAILQ_HEAD(ifsd_external_list, ifsd_external);

 struct ifsd_state {
-	struct event			 ev;
+	struct kevent			 kev;
 	struct ifsd_ifstate_list	 interface_states;
 	struct ifsd_external_list	 external_tests;
 	TAILQ_ENTRY(ifsd_state)		 entries;
@@ -138,6 +139,7 @@
 };

 enum	{ IFSD_EVTIMER_ADD, IFSD_EVTIMER_DEL };
+enum    { IFSD_EVTIMER_STARTUP, IFSD_EVTIMER_EXTERNAL };
 struct ifsd_config *parse_config(char *, int);
 int	cmdline_symset(char *);
 void	clear_config(struct ifsd_config *);
