
$FreeBSD$

--- SDLnetselect.c	2001/07/25 09:44:01	1.1
+++ SDLnetselect.c	2001/07/25 09:45:57
@@ -175,6 +175,7 @@
 	SOCKET maxfd;
 	int retval;
 	struct timeval tv;
+	struct timeval *tmp;
 	fd_set mask;
 
 	/* Find the largest file descriptor */
@@ -199,8 +200,14 @@
 		tv.tv_sec = timeout/1000;
 		tv.tv_usec = (timeout%1000)*1000;
 
+		/* XXX: Workaround for a bug in FreeBSD - w/o it in some cases select() chews 100% CPU */
+		if (timeout == ~0)
+			tmp = NULL;
+		else
+			tmp = &tv;
+
 		/* Look! */
-		retval = select(maxfd+1, &mask, NULL, NULL, &tv);
+		retval = select(maxfd+1, &mask, NULL, NULL, tmp);
 	} while ( errno == EINTR );
 
 	/* Mark all file descriptors ready that have data available */
