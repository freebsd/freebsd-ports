--- ./urlsnarf.c.orig	2001-03-15 10:26:13.000000000 +0100
+++ ./urlsnarf.c	2014-07-22 13:20:14.000000000 +0200
@@ -145,14 +145,14 @@
 		if (user == NULL)
 			user = "-";
 		if (vhost == NULL)
-			vhost = libnet_host_lookup(addr->daddr, Opt_dns);
+			vhost = libnet_addr2name4(addr->daddr, Opt_dns);
 		if (referer == NULL)
 			referer = "-";
 		if (agent == NULL)
 			agent = "-";
 		
 		printf("%s - %s [%s] \"%s http://%s%s\" - - \"%s\" \"%s\"\n",
-		       libnet_host_lookup(addr->saddr, Opt_dns),
+		       libnet_addr2name4(addr->saddr, Opt_dns),
 		       user, timestamp(), req, vhost, uri, referer, agent);
 	}
 	fflush(stdout);
