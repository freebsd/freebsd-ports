--- src/osdep/unix/env_unix.c.orig	2022-04-17 00:12:02 UTC
+++ src/osdep/unix/env_unix.c
@@ -79,7 +79,7 @@ static char *sslDHParams = NIL;	/* specified SSL Diffi
 static short anonymous = NIL;	/* is anonymous */
 static short blackBox = NIL;	/* is a black box */
 static short closedBox = NIL;	/* is a closed box (uses chroot() jail) */
-static long restrictBox = NIL;	/* is a restricted box */
+static long restrictBox = -1;	/* is a restricted box */
 static short has_no_life = NIL;	/* is a cretin with no life */
 				/* block environment init */
 static short block_env_init = NIL;
