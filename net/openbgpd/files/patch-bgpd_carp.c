Index: bgpd/carp.c
===================================================================
RCS file: /home/cvs/private/hrs/openbgpd/bgpd/carp.c,v
retrieving revision 1.1.1.1
retrieving revision 1.2
diff -u -p -r1.1.1.1 -r1.2
--- bgpd/carp.c	30 Jun 2009 05:46:15 -0000	1.1.1.1
+++ bgpd/carp.c	30 Jun 2009 06:40:07 -0000	1.2
@@ -102,6 +102,9 @@ carp_demote_shutdown(void)
 int
 carp_demote_get(char *group)
 {
+#if defined(__FreeBSD__)	/* FreeBSD does not have support for CARP */
+	return (-1);
+#else
 	int			s;
 	struct ifgroupreq	ifgr;
 
@@ -124,6 +127,7 @@ carp_demote_get(char *group)
 
 	close(s);
 	return ((int)ifgr.ifgr_attrib.ifg_carp_demoted);
+#endif /* defined(__FreeBSD__) */
 }
 
 int
@@ -156,6 +160,9 @@ carp_demote_set(char *group, int demote)
 int
 carp_demote_ioctl(char *group, int demote)
 {
+#if defined(__FreeBSD__)	/* FreeBSD does not have support for CARP */
+	return (-1);
+#else
 	int			s, res;
 	struct ifgroupreq	ifgr;
 
@@ -178,4 +185,5 @@ carp_demote_ioctl(char *group, int demot
 
 	close(s);
 	return (res);
+#endif /* defined(__FreeBSD__) */
 }
