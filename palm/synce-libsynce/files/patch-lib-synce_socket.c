--- lib/synce_socket.c.orig	Thu Sep 14 17:38:41 2006
+++ lib/synce_socket.c	Fri Jan 26 01:18:32 2007
@@ -138,32 +138,31 @@
 
 bool synce_socket_connect_proxy(SynceSocket* syncesock, const char* remoteIpAddress)
 {
+    char *path;
+    char socketPath[256];
+    struct sockaddr_un proxyaddr;
+    size_t size;
+
     synce_socket_close(syncesock);
 
     if (!synce_socket_create_proxy(syncesock))
         goto fail;
 
 
-    char *path;
-
     if (!synce_get_subdirectory("rapi2", &path)) {
         goto fail;
     }
 
-    char socketPath[256];
-
     strncpy(socketPath, path, 256);
     strncat(socketPath, "/", 256 - strlen(socketPath));
     strncat(socketPath, remoteIpAddress, 256 - strlen(socketPath));
 
     free(path);
 
-    struct sockaddr_un proxyaddr;
-
     proxyaddr.sun_family = AF_LOCAL;
     strncpy(proxyaddr.sun_path, socketPath, sizeof(proxyaddr.sun_path));
 
-    size_t size = (offsetof (struct sockaddr_un, sun_path) + strlen(proxyaddr.sun_path) + 1);
+    size = (offsetof (struct sockaddr_un, sun_path) + strlen(proxyaddr.sun_path) + 1);
 
     if (connect(syncesock->fd, (struct sockaddr *) &proxyaddr, size) < 0)
         goto fail;
