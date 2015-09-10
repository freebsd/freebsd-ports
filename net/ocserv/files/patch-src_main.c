--- src/main.c.orig	2015-08-31 19:19:45 UTC
+++ src/main.c
@@ -135,8 +135,9 @@ int y;
 #elif defined(IP_RECVDSTADDR) /* *BSD */
 	if (family == AF_INET) {
 		y = 1;
-		if (setsockopt(fd, IPPROTO_IP, IP_RECVDSTADDR,
-			       (const void *)&y, sizeof(y)) < 0)
+        if (family == AF_INET &&
+            setsockopt(fd, IPPROTO_IP, IP_RECVDSTADDR,
+                (const void *)&y, sizeof(y)) < 0)
 			perror("setsockopt(IP_RECVDSTADDR) failed");
 	}
 #endif
