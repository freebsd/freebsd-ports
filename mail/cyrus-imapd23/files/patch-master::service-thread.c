Index: master/service-thread.c
diff -u master/service-thread.c.orig master/service-thread.c
--- master/service-thread.c.orig	Wed Jan 22 22:52:36 2003
+++ master/service-thread.c	Wed Jan 22 23:09:52 2003
@@ -99,6 +99,9 @@
     struct sockaddr_storage sin;
     socklen_t len = sizeof(sin);
     
+    /* XXX: old FreeBSD didn't fill sockaddr correctly against AF_UNIX */
+    sin.ss_family = AF_UNIX;
+
     /* is this a connection from the local host? */
     if (getpeername(fd, (struct sockaddr *) &sin, &len) == 0) {
 	if (((struct sockaddr *)&sin)->sa_family == AF_UNIX) {
