
$FreeBSD$

--- src/icmp.c.orig
+++ src/icmp.c
@@ -197,7 +197,7 @@
 	debug("checking CMSG...");
 	for (c = CMSG_FIRSTHDR(&msg); c; c = CMSG_NXTHDR(&msg, c)) {
 		debug("CMSG level: %i type: %i",c->cmsg_level,c->cmsg_type);
-		if (c->cmsg_level != SOL_SOCKET || c->cmsg_type != SO_TIMESTAMP)
+		if (c->cmsg_level != SOL_SOCKET || c->cmsg_type != SCM_TIMESTAMP)
 			continue;
 		if (c->cmsg_len < CMSG_LEN(sizeof(struct timeval)))
 			continue;
