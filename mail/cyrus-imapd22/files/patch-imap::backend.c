Index: imap/backend.c
diff -u -p imap/backend.c.orig imap/backend.c
--- imap/backend.c.orig	Wed Feb  8 05:57:27 2006
+++ imap/backend.c	Sun Apr  2 13:39:57 2006
@@ -271,7 +271,7 @@ struct backend *backend_connect(struct b
     /* need to (re)establish connection to server or create one */
     int sock = -1;
     int r;
-    int err = 0;
+    int err = -1;
     struct addrinfo hints, *res0 = NULL, *res1 = NULL, *res;
     struct sockaddr_un sunsock;
     char buf[2048], *mechlist = NULL;
