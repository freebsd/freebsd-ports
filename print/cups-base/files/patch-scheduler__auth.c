--- scheduler/auth.c.orig
+++ scheduler/auth.c
@@ -556,7 +556,7 @@
 
     peersize = sizeof(peercred);
 
-#  ifdef __APPLE__
+#  if defined(__APPLE__) || defined(__FreeBSD__)
     if (getsockopt(con->http.fd, 0, LOCAL_PEERCRED, &peercred, &peersize))
 #  else
     if (getsockopt(con->http.fd, SOL_SOCKET, SO_PEERCRED, &peercred, &peersize))
@@ -1155,7 +1155,7 @@
 
       peersize = sizeof(peercred);
 
-#    ifdef __APPLE__
+#    if defined(__APPLE__) || defined(__FreeBSD__)
       if (getsockopt(con->http.fd, 0, LOCAL_PEERCRED, &peercred, &peersize))
 #    else
       if (getsockopt(con->http.fd, SOL_SOCKET, SO_PEERCRED, &peercred,
