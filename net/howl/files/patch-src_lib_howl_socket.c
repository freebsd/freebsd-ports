--- src/lib/howl/socket.c.orig	Sun Oct 17 19:34:00 2004
+++ src/lib/howl/socket.c	Sun Oct 17 19:34:12 2004
@@ -261,7 +261,7 @@
 	err = sw_translate_error(self->m_desc != SW_INVALID_SOCKET, sw_socket_errno());
 	sw_check_okay_log(err, exit);
 
-#if defined(__APPLE__) || defined(__VXWORKS__)
+#if defined(__APPLE__) || defined(__VXWORKS__) || defined(__FreeBSD__)
    res = setsockopt(self->m_desc, SOL_SOCKET, SO_REUSEPORT, (char*) &opt, sizeof(opt));
 #else
 	res = setsockopt(self->m_desc, SOL_SOCKET, SO_REUSEADDR, (char*) &opt, sizeof(opt));
