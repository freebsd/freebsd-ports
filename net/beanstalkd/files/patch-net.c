--- net.c.orig	2022-09-17 01:28:31 UTC
+++ net.c
@@ -158,7 +158,7 @@ make_unix_socket(char *path)
     memset(&addr, 0, sizeof(struct sockaddr_un));
     addr.sun_family = AF_UNIX;
     if (strlen(path) > maxlen) {
-        warnx("socket path %s is too long (%ld characters), where maximum allowed is %ld",
+        warnx("socket path %s is too long (%zu characters), where maximum allowed is %zu",
               path, strlen(path), maxlen);
         return -1;
     }
