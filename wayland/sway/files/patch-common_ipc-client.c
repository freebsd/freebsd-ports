--- common/ipc-client.c.orig	2016-08-02 11:35:25 UTC
+++ common/ipc-client.c
@@ -11,6 +11,7 @@
 #include "ipc.h"
 #include "readline.h"
 #include "ipc-client.h"
+#include <errno.h>
 
 static const char ipc_magic[] = {'i', '3', '-', 'i', 'p', 'c'};
 static const size_t ipc_header_size = sizeof(ipc_magic)+8;
@@ -34,7 +35,7 @@ int ipc_open_socket(const char *socket_p
 	addr.sun_family = AF_UNIX;
 	strncpy(addr.sun_path, socket_path, sizeof(addr.sun_path));
 	addr.sun_path[sizeof(addr.sun_path) - 1] = 0;
-	int l = sizeof(addr.sun_family) + strlen(addr.sun_path);
+	int l = sizeof(struct sockaddr_un);
 	if (connect(socketfd, (struct sockaddr *)&addr, l) == -1) {
 		sway_abort("Unable to connect to %s", socket_path);
 	}
