Index: master/service-thread.c
diff -u master/service-thread.c.orig master/service-thread.c
--- master/service-thread.c.orig	Fri Sep 13 18:43:06 2002
+++ master/service-thread.c	Fri Sep 13 19:15:50 2002
@@ -100,8 +100,13 @@
     socklen_t len = sizeof(sin);
     
     /* is this a connection from the local host? */
+    memset(&sin, 0, len);
     if (getpeername(fd, (struct sockaddr *) &sin, &len) == 0) {
-	if (((struct sockaddr *)&sin)->sa_family == AF_UNIX) {
+	switch (((struct sockaddr *)&sin)->sa_family) {
+	case AF_INET:
+	case AF_INET6:
+	    break;
+	default:
 	    return 1;
 	}
     }
