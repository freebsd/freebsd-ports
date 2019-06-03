Index: bgpd/timer.c
===================================================================
RCS file: /home/cvs/private/hrs/openbgpd/bgpd/timer.c,v
retrieving revision 1.1.1.2
retrieving revision 1.1.1.4
diff -u -p -r1.1.1.2 -r1.1.1.4
--- bgpd/timer.c	9 Jul 2009 16:49:54 -0000	1.1.1.2
+++ bgpd/timer.c	13 Oct 2012 18:22:50 -0000	1.1.1.4
@@ -1,4 +1,4 @@
-/*	$OpenBSD: timer.c,v 1.13 2009/01/21 20:32:53 henning Exp $ */
+/*	$OpenBSD: timer.c,v 1.14 2010/10/24 17:20:08 deraadt Exp $ */
 
 /*
  * Copyright (c) 2003-2007 Henning Brauer <henning@openbsd.org>
@@ -23,8 +23,6 @@
 #include "bgpd.h"
 #include "session.h"
 
-time_t	getmonotime(void);
-
 time_t
 getmonotime(void)
 {
@@ -43,7 +41,7 @@ timer_get(struct peer *p, enum Timer tim
 
 	TAILQ_FOREACH(pt, &p->timers, entry)
 		if (pt->type == timer)
-				break;
+			break;
 
 	return (pt);
 }
