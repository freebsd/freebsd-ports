--- src/lib/torsocks.c.orig	2018-11-20 17:48:42 UTC
+++ src/lib/torsocks.c
@@ -234,9 +234,9 @@ static void init_libc_symbols(void)
 	tsocks_libc_socket = dlsym(libc_ptr, LIBC_SOCKET_NAME_STR);
 	tsocks_libc_syscall = dlsym(libc_ptr, LIBC_SYSCALL_NAME_STR);
 	tsocks_libc_execve = dlsym(libc_ptr, LIBC_EXECVE_NAME_STR);
-	tsocks_libc_accept4 = dlsym(libc_ptr, LIBC_ACCEPT4_NAME_STR);
+	tsocks_libc_accept = dlsym(libc_ptr, LIBC_ACCEPT_NAME_STR);
 	if (!tsocks_libc_connect || !tsocks_libc_close || !tsocks_libc_socket ||
-			!tsocks_libc_syscall || !tsocks_libc_execve || ! tsocks_libc_accept4) {
+			!tsocks_libc_syscall || !tsocks_libc_execve || ! tsocks_libc_accept) {
 		ERR("Unable to lookup symbols in " LIBC_NAME "(%s)", dlerror());
 		goto error;
 	}
