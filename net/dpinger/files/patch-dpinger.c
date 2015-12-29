--- dpinger.c.orig	2015-12-29 10:25:51 UTC
+++ dpinger.c
@@ -1106,13 +1106,19 @@ main(
             fatal("socket name too large\n");
         }
 
-        usocket_fd = socket(AF_UNIX, SOCK_STREAM | SOCK_CLOEXEC, 0);
+        usocket_fd = socket(AF_UNIX, SOCK_STREAM, 0);
         if (usocket_fd == -1)
         {
             perror("socket");
             fatal("cannot create unix domain socket\n");
         }
 
+        if (fcntl(usocket_fd, F_SETFD, FD_CLOEXEC) == -1)
+        {
+            perror("socket");
+            fatal("cannot set cloexec on unix domain socket\n");
+        }
+
         (void) unlink(usocket_name);
 
         memset(&uaddr, 0, sizeof(uaddr));
