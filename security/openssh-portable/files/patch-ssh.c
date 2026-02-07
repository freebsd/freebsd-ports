--- UTC
r99054 | des | 2002-06-29 05:57:53 -0500 (Sat, 29 Jun 2002) | 4 lines
Changed paths:
   M /head/crypto/openssh/ssh.c

Canonicize the host name before looking it up in the host file.

--- ssh.c.orig	2018-04-02 05:38:28 UTC
+++ ssh.c
@@ -1281,6 +1281,23 @@ main(int ac, char **av)
 	ssh_digest_free(md);
 	conn_hash_hex = tohex(conn_hash, ssh_digest_bytes(SSH_DIGEST_SHA1));
 
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
 	 * Expand tokens in arguments. NB. LocalCommand is expanded later,
 	 * after port-forwarding is set up, so it may pick up any local
