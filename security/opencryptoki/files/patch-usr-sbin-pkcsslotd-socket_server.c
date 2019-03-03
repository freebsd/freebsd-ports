--- usr/sbin/pkcsslotd/socket_server.c.orig	2018-11-16 14:53:03 UTC
+++ usr/sbin/pkcsslotd/socket_server.c
@@ -19,6 +19,9 @@
 #include <sys/select.h>
 #include <sys/stat.h>
 #include <grp.h>
+#ifndef SOCK_NONBLOCK
+#include <fcntl.h>
+#endif
 
 #include "log.h"
 #include "slotmgr.h"
@@ -34,11 +37,23 @@ int CreateListenerSocket(void)
     struct group *grp;
     int socketfd;
 
+#ifdef SOCK_NONBLOCK
     socketfd = socket(PF_UNIX, SOCK_STREAM | SOCK_NONBLOCK, 0);
+#else
+    socketfd = socket(PF_UNIX, SOCK_STREAM, 0);
+#endif
     if (socketfd < 0) {
         ErrLog("Failed to create listener socket, errno 0x%X.", errno);
         return -1;
     }
+#ifndef  SOCK_NONBLOCK
+    if (fcntl(socketfd, F_SETFL,
+        fcntl(socketfd, F_GETFL) | O_NONBLOCK) < 0) {
+            ErrLog("Failed to set listener non-block, errno 0x%X.", errno);
+            close(socketfd);
+            return -1;
+    }
+#endif
     if (unlink(SOCKET_FILE_PATH) && errno != ENOENT) {
         ErrLog("Failed to unlink socket file, errno 0x%X.", errno);
         close(socketfd);
@@ -57,7 +72,7 @@ int CreateListenerSocket(void)
     }
     // make socket file part of the pkcs11 group, and write accessable
     // for that group
-    grp = getgrnam("pkcs11");
+    grp = getgrnam(PKCS11GROUP);
     if (!grp) {
         ErrLog("Group PKCS#11 does not exist");
         DetachSocketListener(socketfd);
