
$FreeBSD$

--- src/net.c.orig	Wed Dec 11 15:37:56 2002
+++ src/net.c	Sun Mar  7 14:55:10 2004
@@ -122,6 +122,7 @@
 	int sd = 0;
 	unsigned long inaddr;
 	struct sockaddr_in addr;
+	int true = 1;
 
 	memset(&addr, 0, sizeof(addr));
 	addr.sin_family = AF_INET;
@@ -152,6 +153,8 @@
 	}
 	else
 		addr.sin_addr.s_addr = htonl(INADDR_ANY);
+
+	setsockopt (sd, SOL_SOCKET, SO_REUSEADDR, &true, sizeof(true));
 
 	if (bind(sd, (struct sockaddr *)&addr, sizeof(addr)))
 		anubis_error(HARD, _("bind() failed: %s."), strerror(errno));
