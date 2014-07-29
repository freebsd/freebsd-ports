--- mupdisp/mupdisp.c.orig	Tue Jun 22 09:18:32 2004
+++ mupdisp/mupdisp.c	Wed Mar  2 16:19:53 2005
@@ -45,6 +45,10 @@
  *	chmod 4755 mupdisp
  */
 
+#include <stdio.h>
+#include <stdlib.h>
+#include <unistd.h>
+#include <sys/signal.h>
 
 #include "mupdisp.h"
 #ifdef __WATCOMC__
@@ -112,7 +116,7 @@
 	/* arrange to clean up temp files. Note that the user interface
 	 * will probably have its own cleanup */
 	for (n = 0; n < NSIG; n++) {
-		if (n != SIGKILL && n != SIGCLD && n != SIGWINCH) {
+		if (n != SIGKILL && n != SIGCHLD && n != SIGWINCH) {
 			signal(n, generalcleanup);
 		}
 	}
@@ -314,7 +318,7 @@
 	int fd;
 
 
-#ifdef linux
+#if defined(linux) || defined(__FreeBSD__)
 	if ((fd = mkstemp(tmpfname)) < 0) {
 		fprintf(stderr, "can't create temp file\n");
 		generalcleanup(1);
