--- sockets.c.orig	2011/05/23 23:51:28
+++ sockets.c	2011/05/24 00:05:50
@@ -1336,6 +1336,11 @@
 			break;
 
 		case AF_UNIX:
+			if (addr_len >= sizeof(s_un.sun_path)) {
+				php_error_docref(NULL TSRMLS_CC, E_WARNING, "Path too long", php_sock->type);
+				RETURN_FALSE;
+			}
+				
 			memset(&s_un, 0, sizeof(struct sockaddr_un));
 
 			s_un.sun_family = AF_UNIX;
