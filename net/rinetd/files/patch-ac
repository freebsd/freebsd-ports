--- rinetd.c.orig	Thu Jul 19 22:19:59 2001
+++ rinetd.c	Thu Jul 19 22:20:26 2001
@@ -243,6 +243,7 @@
 			signal(SIGHUP, hup);
 #endif /* WIN32 */
 			signal(SIGTERM, term);
+			setsid();
 			initArrays();
 			readConfiguration();
 			RegisterPID();
