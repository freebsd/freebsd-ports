--- src/osdep/unix/env_unix.c.orig	Mon Sep 13 23:31:19 2004
+++ src/osdep/unix/env_unix.c	Fri Nov 25 20:44:01 2005
@@ -44,7 +44,7 @@
 static short anonymous = NIL;	/* is anonymous */
 static short blackBox = NIL;	/* is a black box */
 static short closedBox = NIL;	/* is a closed box */
-static short restrictBox = NIL;	/* is a restricted box */
+static short restrictBox = -1;	/* is a restricted box */
 static short has_no_life = NIL;	/* is a cretin with no life */
 				/* flock() emulator is a no-op */
 static short disableFcntlLock = NIL;
