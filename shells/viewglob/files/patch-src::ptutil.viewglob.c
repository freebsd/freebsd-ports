--- src/ptutil.viewglob.c.orig	Wed Oct  6 03:34:54 2004
+++ src/ptutil.viewglob.c	Wed Oct  6 03:47:51 2004
@@ -45,7 +45,6 @@
 #endif
 /*[incl]*/
 #ifdef _XOPEN_UNIX
-#include <stropts.h> /* for STREAMS */
 #endif
 #ifdef NEED_TIOCSCTTY
 #include <sys/ttycom.h> /* for TIOCSCTTY */
@@ -73,14 +72,9 @@
 static bool find_and_open_master(PTINFO *p)
 {
 #if defined(_XOPEN_UNIX)
-#if _XOPEN_VERSION >= 600
 	p->pt_name_m[0] = '\0'; /* don't know or need name */
-	ec_neg1( p->pt_fd_m = posix_openpt(O_RDWR | O_NOCTTY) )
-#else
-	strcpy(p->pt_name_m, "/dev/ptmx"); /* clone device */
-	if ( (p->pt_fd_m = open(p->pt_name_m, O_RDWR)) == -1)
-		goto failure;
-#endif
+	if ((p->pt_fd_m = posix_openpt(O_RDWR | O_NOCTTY)) == -1)
+		return false;
 #elif defined(MASTER_NAME_SEARCH)
 	int i, j;
 	char proto[] = PTY_PROTO;
