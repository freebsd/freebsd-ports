--- src/main.c.orig	2023-06-16 17:01:03 UTC
+++ src/main.c
@@ -215,9 +215,9 @@ int _listen_ports(void *pool, struct perm_cfg_st* conf
 #endif
 
 		y = 1;
-		if (setsockopt(s, SOL_SOCKET, SO_REUSEADDR,
+		if (setsockopt(s, SOL_SOCKET, SO_REUSEPORT,
 			       (const void *) &y, sizeof(y)) < 0) {
-			perror("setsockopt(SO_REUSEADDR) failed");
+			perror("setsockopt(SO_REUSEPORT) failed");
 		}
 
 		if (ptr->ai_socktype == SOCK_DGRAM) {
@@ -424,8 +424,8 @@ int y;
 #endif
 
 	y = 1;
-	if (setsockopt(fd, SOL_SOCKET, SO_REUSEADDR, (const void *) &y, sizeof(y)) < 0) {
-		perror("setsockopt(SO_REUSEADDR) failed");
+	if (setsockopt(fd, SOL_SOCKET, SO_REUSEPORT, (const void *) &y, sizeof(y)) < 0) {
+		perror("setsockopt(SO_REUSEPORT) failed");
 	}
 
 	if (GETCONFIG(s)->try_mtu) {
