--- wmwork.c.orig	Sat Oct 19 23:43:16 2002
+++ wmwork.c	Tue Oct 22 02:35:15 2002
@@ -68,7 +68,11 @@
 		*geometry = NULL,
 		*xdisplay = NULL;
 	static int signals[] =
+#if defined(__FreeBSD__)
+		{SIGALRM, SIGHUP, SIGINT, SIGPIPE, SIGTERM, SIGUSR1, SIGUSR2, 0};
+#else
 		{SIGALRM, SIGHUP, SIGINT, SIGPIPE, SIGPOLL, SIGTERM, SIGUSR1, SIGUSR2, 0};
+#endif
 	XEvent Event;
 
 	assert(sizeof(char) == 1);
