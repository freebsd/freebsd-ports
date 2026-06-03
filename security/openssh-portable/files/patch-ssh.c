--- UTC
r99054 | des | 2002-06-29 05:57:53 -0500 (Sat, 29 Jun 2002) | 4 lines
Changed paths:
   M /head/crypto/openssh/ssh.c

Canonicize the host name before looking it up in the host file.

--- ssh.c.orig	2018-04-02 05:38:28 UTC
+++ ssh.c
@@ -1289,6 +1289,23 @@ main(int ac, char **av)
 			check_follow_cname(direct, &host, cname);
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
 	/*
 	 * If canonicalisation is enabled then re-parse the configuration
 	 * files as new stanzas may match.
