--- ssh.c.orig	Sat Sep  2 02:32:40 2006
+++ ssh.c	Sat Sep 30 10:38:05 2006
@@ -639,6 +640,23 @@
 
 	if (options.hostname != NULL)
 		host = options.hostname;
+
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
 
 	/* force lowercase for hostkey matching */
 	if (options.host_key_alias != NULL) {
