--- bgpd/carp.c	19 Jun 2006 12:06:24 -0000	1.3
+++ bgpd/carp.c	8 Feb 2007 10:31:16 -0000
@@ -102,28 +102,7 @@ carp_demote_shutdown(void)
 int
 carp_demote_get(char *group)
 {
-	int			s;
-	struct ifgroupreq	ifgr;
-
-	if ((s = socket(AF_INET, SOCK_DGRAM, 0)) == -1) {
-		log_warn("carp_demote_get: socket");
-		return (-1);
-	}
-
-	bzero(&ifgr, sizeof(ifgr));
-	strlcpy(ifgr.ifgr_name, group, sizeof(ifgr.ifgr_name));
-
-	if (ioctl(s, SIOCGIFGATTR, (caddr_t)&ifgr) == -1) {
-		if (errno == ENOENT)
-			log_warnx("group \"%s\" does not exist", group);
-		else
-			log_warn("carp_demote_get: ioctl");
-		close(s);
-		return (-1);
-	}
-
-	close(s);
-	return ((int)ifgr.ifgr_attrib.ifg_carp_demoted);
+	return (-1);
 }
 
 int
@@ -156,26 +135,5 @@ carp_demote_set(char *group, int demote)
 int
 carp_demote_ioctl(char *group, int demote)
 {
-	int			s, res;
-	struct ifgroupreq	ifgr;
-
-	if ((s = socket(AF_INET, SOCK_DGRAM, 0)) == -1) {
-		log_warn("carp_demote_get: socket");
-		return (-1);
-	}
-
-	bzero(&ifgr, sizeof(ifgr));
-	strlcpy(ifgr.ifgr_name, group, sizeof(ifgr.ifgr_name));
-	ifgr.ifgr_attrib.ifg_carp_demoted = demote;
-
-	if ((res = ioctl(s, SIOCSIFGATTR, (caddr_t)&ifgr)) == -1)
-		log_warn("unable to %s the demote state "
-		    "of group '%s'", (demote > 0) ? "increment" : "decrement",
-		    group);
-	else
-		log_info("%s the demote state of group '%s'",
-		    (demote > 0) ? "incremented" : "decremented", group);
-
-	close (s);
-	return (res);
+	return (-1);
 }
Index: kroute.c
===================================================================
RCS file: /cvs/src/usr.sbin/bgpd/kroute.c,v
retrieving revision 1.147
diff -u -p -r1.147 kroute.c
