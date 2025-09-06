--- src/common/sack_api.c.orig	2024-05-21 17:19:51 UTC
+++ src/common/sack_api.c
@@ -38,6 +38,8 @@
 #include <sys/socket.h>
 #include <sys/types.h>
 #include <sys/un.h>
+#include <string.h>
+#include <stddef.h>
 #include <unistd.h>
 
 #include "src/common/fd.h"
@@ -63,7 +65,15 @@ static int _sack_try_connection(struct sockaddr_un *ad
 static int _sack_try_connection(struct sockaddr_un *addr)
 {
 	int fd;
-	size_t len = strlen(addr->sun_path) + 1 + sizeof(addr->sun_family);
+	socklen_t len;
+
+/* FreeBSD requires sun_len and a correct namelen */
+#if defined(__FreeBSD__)
+	len = (socklen_t)SUN_LEN(addr);
+	addr->sun_len = (uint8_t)len;
+#else
+	len = (socklen_t)(strlen(addr->sun_path) + 1 + sizeof(addr->sun_family));
+#endif
 
 	if ((fd = socket(AF_UNIX, SOCK_STREAM, 0)) < 0) {
 		debug3("%s: socket() failed: %m", __func__);
