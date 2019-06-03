Index: bgpd/config.c
===================================================================
RCS file: /home/cvs/private/hrs/openbgpd/bgpd/config.c,v
retrieving revision 1.1.1.6
retrieving revision 1.3
diff -u -p -r1.1.1.6 -r1.3
--- bgpd/config.c	14 Feb 2010 20:19:57 -0000	1.1.1.6
+++ bgpd/config.c	13 Oct 2012 18:36:00 -0000	1.3
@@ -1,4 +1,4 @@
-/*	$OpenBSD: config.c,v 1.51 2009/01/26 23:10:02 claudio Exp $ */
+/*	$OpenBSD: config.c,v 1.55 2010/09/02 14:03:21 sobrado Exp $ */
 
 /*
  * Copyright (c) 2003, 2004, 2005 Henning Brauer <henning@openbsd.org>
@@ -20,6 +20,11 @@
 #include <sys/socket.h>
 #include <sys/stat.h>
 #include <sys/mman.h>
+#include <sys/ioctl.h>
+
+#if !defined(__FreeBSD__) /* FreeBSD has no mpls support. */
+#include <netmpls/mpls.h>
+#endif
 
 #include <errno.h>
 #include <ifaddrs.h>
@@ -47,8 +52,6 @@ merge_config(struct bgpd_config *xconf, 
 
 	/* preserve cmd line opts */
 	conf->opts = xconf->opts;
-	conf->csock = xconf->csock;
-	conf->rcsock = xconf->rcsock;
 
 	if (!conf->as) {
 		log_warnx("configuration error: AS not given");
@@ -64,6 +67,9 @@ merge_config(struct bgpd_config *xconf, 
 	if ((conf->flags & BGPD_FLAG_REFLECTOR) && conf->clusterid == 0)
 		conf->clusterid = conf->bgpid;
 
+	free(xconf->csock);
+	free(xconf->rcsock);
+
 	conf->listen_addrs = xconf->listen_addrs;
 	memcpy(xconf, conf, sizeof(struct bgpd_config));
 
@@ -74,7 +80,7 @@ merge_config(struct bgpd_config *xconf, 
 			nla->reconf = RECONF_REINIT;
 
 	} else {
-		/* 
+		/*
 		 * merge new listeners:
 		 * -flag all existing ones as to be deleted
 		 * -those that are in both new and old: flag to keep
@@ -208,7 +214,7 @@ host_v4(const char *s, struct bgpd_addr 
 			return (0);
 	}
 
-	h->af = AF_INET;
+	h->aid = AID_INET;
 	h->v4.s_addr = ina.s_addr;
 	*len = bits;
 
@@ -225,13 +231,7 @@ host_v6(const char *s, struct bgpd_addr 
 	hints.ai_socktype = SOCK_DGRAM; /*dummy*/
 	hints.ai_flags = AI_NUMERICHOST;
 	if (getaddrinfo(s, "0", &hints, &res) == 0) {
-		h->af = AF_INET6;
-		memcpy(&h->v6,
-		    &((struct sockaddr_in6 *)res->ai_addr)->sin6_addr,
-		    sizeof(h->v6));
-		h->scope_id =
-		    ((struct sockaddr_in6 *)res->ai_addr)->sin6_scope_id;
-
+		sa2addr(res->ai_addr, h);
 		freeaddrinfo(res);
 		return (1);
 	}
@@ -317,3 +317,30 @@ prepare_listeners(struct bgpd_config *co
 		}
 	}
 }
+
+int
+get_mpe_label(struct rdomain *r)
+{
+#if !defined(__FreeBSD__) /* FreeBSD has no mpls support. */
+	struct  ifreq	ifr;
+	struct shim_hdr	shim;
+	int		s;
+
+	s = socket(AF_INET, SOCK_DGRAM, 0);
+	if (s == -1)
+		return (-1);
+
+	bzero(&shim, sizeof(shim));
+	bzero(&ifr, sizeof(ifr));
+	strlcpy(ifr.ifr_name, r->ifmpe, sizeof(ifr.ifr_name));
+	ifr.ifr_data = (caddr_t)&shim;
+
+	if (ioctl(s, SIOCGETLABEL, (caddr_t)&ifr) == -1) {
+		close(s);
+		return (-1);
+	}
+	close(s);
+	r->label = shim.shim_label;
+#endif
+	return (0);
+}
