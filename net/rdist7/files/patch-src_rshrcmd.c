--- src/rshrcmd.c.orig	1998-11-10 04:15:07 UTC
+++ src/rshrcmd.c
@@ -41,19 +41,11 @@ rshrcmd(ahost, port, luser, ruser, cmd, fd2p)
 	int	*fd2p;
 {
 	int             cpid;
-	struct hostent  *hp;
 	int             sp[2];
 
 	/* insure that we are indeed being used as we thought. */
 	if (fd2p != 0)
 		return -1;
-	/* validate remote hostname. */
-	hp = gethostbyname(*ahost);
-	if (hp == 0) {
-		error("%s: unknown host", *ahost);
-		return -1;
-	}
-	/* *ahost = hp->h_name;*/ /* This makes me nervous. */
 
 	/* get a socketpair we'll use for stdin and stdout. */
 	if (getsocketpair(AF_UNIX, SOCK_STREAM, 0, sp) < 0) {
