--- bgpd/carp.c	2007-04-23 16:52:28.000000000 +0200
+++ bgpd/carp.c	2008-03-18 13:27:29.000000000 +0100
@@ -102,28 +102,7 @@
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
 		return (-1);
-	}
-
-	close(s);
-	return ((int)ifgr.ifgr_attrib.ifg_carp_demoted);
 }
 
 int
@@ -156,26 +135,5 @@
 int
 carp_demote_ioctl(char *group, int demote)
 {
-	int			s, res;
-	struct ifgroupreq	ifgr;
-
-	if ((s = socket(AF_INET, SOCK_DGRAM, 0)) == -1) {
-		log_warn("carp_demote_get: socket");
 		return (-1);
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
-	close(s);
-	return (res);
 }
