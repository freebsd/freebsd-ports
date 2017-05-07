--- tests/connection-test.c.orig	2016-02-17 01:13:16 UTC
+++ tests/connection-test.c
@@ -36,6 +36,7 @@
 #include <sys/stat.h>
 #include <poll.h>
 
+#include "wayland-os.h"
 #include "wayland-private.h"
 #include "test-runner.h"
 #include "test-compositor.h"
@@ -47,7 +48,7 @@ setup(int *s)
 {
 	struct wl_connection *connection;
 
-	assert(socketpair(AF_UNIX, SOCK_STREAM | SOCK_CLOEXEC, 0, s) == 0);
+	assert(wl_os_socketpair_cloexec(AF_UNIX, SOCK_STREAM, 0, s) == 0);
 
 	connection = wl_connection_create(s[0]);
 	assert(connection);
@@ -145,8 +146,7 @@ struct marshal_data {
 static void
 setup_marshal_data(struct marshal_data *data)
 {
-	assert(socketpair(AF_UNIX,
-			  SOCK_STREAM | SOCK_CLOEXEC, 0, data->s) == 0);
+	assert(wl_os_socketpair_cloexec(AF_UNIX, SOCK_STREAM, 0, data->s) == 0);
 	data->read_connection = wl_connection_create(data->s[0]);
 	assert(data->read_connection);
 	data->write_connection = wl_connection_create(data->s[1]);
