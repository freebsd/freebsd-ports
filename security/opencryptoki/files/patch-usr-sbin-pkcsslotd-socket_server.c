--- usr/sbin/pkcsslotd/socket_server.c.orig	2022-04-25 11:04:51 UTC
+++ usr/sbin/pkcsslotd/socket_server.c
@@ -18,6 +18,9 @@
 #include <stdlib.h>
 #include <fcntl.h>
 
+#if defined(__FreeBSD__)
+#include <sys/ucred.h>
+#endif
 #include <sys/time.h>
 #include <sys/socket.h>
 #include <sys/un.h>
@@ -641,7 +644,11 @@ static int proc_new_conn(int socket, struct listener_i
     struct proc_conn_info *conn;
     struct event_info *event;
     DL_NODE *list, *node;
+#if !defined(__FreeBSD__)
     struct ucred ucred;
+#else
+    struct xucred ucred;
+#endif
     socklen_t  len;
     int rc = 0;
 
@@ -661,21 +668,34 @@ static int proc_new_conn(int socket, struct listener_i
     DbgLog(DL3, "%s: process conn: %p", __func__, conn);
 
     len = sizeof(ucred);
+#if !defined(__FreeBSD__)
     rc = getsockopt(socket, SOL_SOCKET, SO_PEERCRED, &ucred, &len);
+#else
+    rc = getsockopt(socket, 0, LOCAL_PEERCRED, &ucred, &len);
+#endif
     if (rc != 0 || len != sizeof(ucred)) {
         rc = -errno;
-        ErrLog("%s: failed get credentials of peer process: %s",
-               strerror(-rc), __func__);
+        ErrLog("%s: failed get credentials of peer process: %s (len=%zu)",
+               __func__, strerror(-rc), len);
         goto out;
     }
 
+#if !defined(__FreeBSD__)
     DbgLog(DL3, "%s: process pid: %u uid: %u gid: %u", __func__,
            ucred.pid, ucred.uid, ucred.gid);
 
     conn->client_cred.real_pid = ucred.pid;
     conn->client_cred.real_uid = ucred.uid;
     conn->client_cred.real_gid = ucred.gid;
+#else
+    DbgLog(DL3, "%s: process pid: %u uid: %u gid: %u", __func__,
+           ucred.cr_pid, ucred.cr_uid, ucred.cr_gid);
 
+    conn->client_cred.real_pid = ucred.cr_pid;
+    conn->client_cred.real_uid = ucred.cr_uid;
+    conn->client_cred.real_gid = ucred.cr_gid;
+#endif
+
     /* Add currently pending events to this connection */
     node = dlist_get_first(pending_events);
     while (node != NULL) {
@@ -1280,13 +1300,13 @@ static int listener_socket_create(const char *file_pat
     if (bind(listener_socket,
              (struct sockaddr *) &address, sizeof(struct sockaddr_un)) != 0) {
         err = errno;
-        ErrLog("%s: Failed to bind to socket, errno %d (%s).", __func__, err,
-               strerror(err));
+        ErrLog("%s: Failed to bind to socket, errno %d (%s): %s", __func__, err,
+               strerror(err), address.sun_path);
         goto error;
     }
     // make socket file part of the pkcs11 group, and write accessable
     // for that group
-    grp = getgrnam("pkcs11");
+    grp = getgrnam(PKCS11GROUP);
     if (!grp) {
         ErrLog("%s: Group PKCS#11 does not exist", __func__);
         goto error;
@@ -1408,7 +1428,9 @@ static int listener_create(const char *file_path,
     if (listener->socket < 0)
         return FALSE;
 
+    memset(&evt, 0, sizeof(evt));
     evt.events = EPOLLIN | EPOLLET;
+    evt.data.fd = listener->socket;
     evt.data.ptr = &listener->ep_info;
     rc = epoll_ctl(epoll_fd, EPOLL_CTL_ADD, listener->socket, &evt);
     if (rc != 0) {
@@ -1693,8 +1715,8 @@ int socket_connection_handler(int timeout_secs)
             err = errno;
             if (err == EINTR)
                 continue;
-            ErrLog("%s: epoll_wait failed, errno %d (%s).", __func__, err,
-                   strerror(err));
+            ErrLog("%s: epoll_wait failed, errno %d (%s): %d", __func__, err,
+                   strerror(err), epoll_fd);
             return FALSE;
         }
 
@@ -1730,8 +1752,8 @@ int init_socket_server(int event_support_disabled)
     epoll_fd = epoll_create1(0);
     if (epoll_fd < 0) {
         err = errno;
-        ErrLog("%s: Failed to open epoll socket, errno %d (%s).", __func__, err,
-               strerror(err));
+        ErrLog("%s: Failed to open epoll socket, errno %d (%s): %d", __func__, err,
+               strerror(err), epoll_fd);
         return FALSE;
     }
 
