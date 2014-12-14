--- src/osdep/unix/env_unix.c.orig	2013-06-21 23:29:17.000000000 +0200
+++ src/osdep/unix/env_unix.c	2014-11-23 22:48:04.000000000 +0100
@@ -76,7 +76,7 @@
 static short anonymous = NIL;	/* is anonymous */
 static short blackBox = NIL;	/* is a black box */
 static short closedBox = NIL;	/* is a closed box (uses chroot() jail) */
-static long restrictBox = NIL;	/* is a restricted box */
+static long restrictBox = -1;	/* is a restricted box */
 static short has_no_life = NIL;	/* is a cretin with no life */
 				/* block environment init */
 static short block_env_init = NIL;
