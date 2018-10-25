commit f08bbef11c77a6a81d4e2bf974e36e54b0cd14d6
Author: Jaroslav Kysela <perex@perex.cz>
Date:   Tue Oct 16 16:51:00 2018 +0200

    Revert "FreeBSD: Fix recv problem if no data received."
   
    This reverts commit 3895c923a3a959da05080831b8146c09ed143b00.

--- src/tcp.c
+++ src/tcp.c
@@ -454,11 +454,8 @@ tcp_socket_dead(int fd)
   if (err)
     return -err;
 #ifdef PLATFORM_FREEBSD
-  err = recv(fd, NULL, 0, MSG_PEEK | MSG_DONTWAIT);
-  if (err < 0)
+  if (recv(fd, NULL, 0, MSG_PEEK | MSG_DONTWAIT) < 0)
     return -errno;
-  else if (err == 0)
-      return -EIO;
 #else
   if (recv(fd, NULL, 0, MSG_PEEK | MSG_DONTWAIT) == 0)
     return -EIO;
