Index: iiimsf/src/iwrap.c
diff -u -p iiimsf/src/iwrap.c.orig iiimsf/src/iwrap.c
--- iiimsf/src/iwrap.c.orig	Thu Sep  9 06:17:09 2004
+++ iiimsf/src/iwrap.c	Tue Feb 22 15:22:41 2005
@@ -72,6 +72,15 @@ int permit_access(
 {
 #ifdef HAVE_LIBWRAP
     struct request_info req;
+    struct sockaddr_storage ss;
+    struct sockaddr *pname = (struct sockaddr*) &ss;
+    socklen_t size;
+
+    size = sizeof(ss);
+    if (getpeername(h, pname, &size) < 0)
+	return 0;
+    if (pname->sa_family == AF_UNIX)
+    	return 1;
 
     request_init(&req, RQ_DAEMON, cmdname, RQ_FILE, h, 0);
     fromhost(&req);
@@ -177,6 +186,14 @@ authenticate_with_unix(
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
