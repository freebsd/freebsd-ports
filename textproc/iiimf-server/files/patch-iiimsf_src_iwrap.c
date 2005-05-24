--- iiimsf/src/iwrap.c.orig	Wed Apr 13 01:51:55 2005
+++ iiimsf/src/iwrap.c	Mon May  9 18:02:18 2005
@@ -72,6 +72,15 @@
 {
 #ifdef HAVE_LIBWRAP
     struct request_info req;
+    struct sockaddr_storage ss;
+    struct sockaddr *pname = (struct sockaddr*) &ss;
+    socklen_t size;
+
+    size = sizeof(ss);
+    if (getpeername(h, pname, &size) < 0)
+       return 0;
+    if (pname->sa_family == AF_UNIX)
+       return 1;
 
     request_init(&req, RQ_DAEMON, cmdname, RQ_FILE, h, 0);
     fromhost(&req);
@@ -177,6 +186,14 @@
 #ifdef HAVE_GETPEEREID
     /* OpenBSD */
     git_t gid;
+
+    if (getpeereid(sock, &uid, &gid) != 0) {
+      return 0;
+    }
+
+#elif defined(__FreeBSD__)
+    /* FreeBSD */
+    gid_t gid = -1;
 
     if (getpeereid(sock, &uid, &gid) != 0) {
       return 0;
