--- src/modules/module-protocol-simple.c.orig	2022-11-24 13:00:46 UTC
+++ src/modules/module-protocol-simple.c
@@ -543,7 +543,7 @@ on_connect(void *data, int fd, uint32_t mask)
 	struct pw_properties *props = NULL;
 
 	addrlen = sizeof(addr);
-	client_fd = accept4(fd, &addr, &addrlen, SOCK_NONBLOCK | SOCK_CLOEXEC);
+	client_fd = accept4(fd, (struct sockaddr*)&addr, &addrlen, SOCK_NONBLOCK | SOCK_CLOEXEC);
 	if (client_fd < 0)
 		goto error;
 
