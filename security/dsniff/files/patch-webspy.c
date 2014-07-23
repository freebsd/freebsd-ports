--- ./webspy.c.orig	2001-03-15 09:33:05.000000000 +0100
+++ ./webspy.c	2014-07-22 13:20:14.000000000 +0200
@@ -126,7 +126,7 @@
 		if (auth == NULL)
 			auth = "";
 		if (vhost == NULL)
-			vhost = libnet_host_lookup(addr->daddr, 0);
+			vhost = libnet_addr2name4(addr->daddr, 0);
 		
 		snprintf(cmd, sizeof(cmd), "openURL(http://%s%s%s%s)",
 			 auth, *auth ? "@" : "", vhost, uri);
@@ -202,7 +202,7 @@
 	cmdtab[0] = cmd;
 	cmdtab[1] = NULL;
 	
-	if ((host = libnet_name_resolve(argv[0], 1)) == -1)
+	if ((host = libnet_name2addr4(NULL, argv[0], 1)) == -1)
 		errx(1, "unknown host");
 	
 	if ((dpy = XOpenDisplay(NULL)) == NULL)
