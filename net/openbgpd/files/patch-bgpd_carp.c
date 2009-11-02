Index: bgpd/carp.c
===================================================================
RCS file: /home/cvs/private/hrs/openbgpd/bgpd/carp.c,v
retrieving revision 1.1.1.1
retrieving revision 1.4
diff -u -p -r1.1.1.1 -r1.4
--- bgpd/carp.c	30 Jun 2009 05:46:15 -0000	1.1.1.1
+++ bgpd/carp.c	22 Oct 2009 15:10:02 -0000	1.4
@@ -1,4 +1,4 @@
-/*	$OpenBSD: carp.c,v 1.5 2007/04/23 14:52:28 claudio Exp $ */
+/*	$OpenBSD: carp.c,v 1.6 2008/09/10 15:00:01 tobias Exp $ */
 
 /*
  * Copyright (c) 2006 Henning Brauer <henning@openbsd.org>
@@ -72,8 +72,11 @@ carp_demote_init(char *group, int force)
 		}
 
 		/* only demote if this group already is demoted */
-		if ((level = carp_demote_get(group)) == -1)
+		if ((level = carp_demote_get(group)) == -1) {
+			free(c->group);
+			free(c);
 			return (-1);
+		}
 		if (level > 0 || force)
 			c->do_demote = 1;
 
@@ -90,9 +93,8 @@ carp_demote_shutdown(void)
 
 	while ((c = TAILQ_FIRST(&carpgroups)) != NULL) {
 		TAILQ_REMOVE(&carpgroups, c, entry);
-		for (; c->changed_by > 0; c->changed_by--)
-			if (c->do_demote)
-				carp_demote_ioctl(c->group, -1);
+		if (c->do_demote && c->changed_by > 0)
+			carp_demote_ioctl(c->group, -c->changed_by);
 
 		free(c->group);
 		free(c);
@@ -102,6 +104,9 @@ carp_demote_shutdown(void)
 int
 carp_demote_get(char *group)
 {
+#if defined(__FreeBSD__)	/* FreeBSD does not have support for CARP */
+	return (-1);
+#else
 	int			s;
 	struct ifgroupreq	ifgr;
 
@@ -124,6 +129,7 @@ carp_demote_get(char *group)
 
 	close(s);
 	return ((int)ifgr.ifgr_attrib.ifg_carp_demoted);
+#endif /* defined(__FreeBSD__) */
 }
 
 int
@@ -156,6 +162,9 @@ carp_demote_set(char *group, int demote)
 int
 carp_demote_ioctl(char *group, int demote)
 {
+#if defined(__FreeBSD__)	/* FreeBSD does not have support for CARP */
+	return (-1);
+#else
 	int			s, res;
 	struct ifgroupreq	ifgr;
 
@@ -178,4 +187,5 @@ carp_demote_ioctl(char *group, int demot
 
 	close(s);
 	return (res);
+#endif /* defined(__FreeBSD__) */
 }
