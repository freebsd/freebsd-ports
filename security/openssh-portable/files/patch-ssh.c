$FreeBSD$

Make the same change to use the canonical hostname as the base FreeBSD ssh.

--- ssh.c.orig	2010-08-16 09:59:31.000000000 -0600
+++ ssh.c	2010-08-25 17:55:01.000000000 -0600
@@ -699,6 +699,23 @@
 		    "h", host, (char *)NULL);
 	}
 
+	/* Find canonic host name. */
+	if (strchr(host, '.') == 0) {
+		struct addrinfo hints;
+		struct addrinfo *ai = NULL;
+		int errgai;
+		memset(&hints, 0, sizeof(hints));
+		hints.ai_family = options.address_family;
+		hints.ai_flags = AI_CANONNAME;
+		hints.ai_socktype = SOCK_STREAM;
+		errgai = getaddrinfo(host, NULL, &hints, &ai);
+		if (errgai == 0) {
+			if (ai->ai_canonname != NULL)
+				host = xstrdup(ai->ai_canonname);
+			freeaddrinfo(ai);
+		}
+	}
+
 	if (options.local_command != NULL) {
 		char thishost[NI_MAXHOST];
 
