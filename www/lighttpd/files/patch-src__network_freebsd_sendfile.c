#
# Respect EAGAIN and retry sendfile() instead close connection.
# Remove empty lines and add two more cases to switch(errno)
#
--- src/network_freebsd_sendfile.c.orig	2007-09-22 19:55:26.000000000 -0300
+++ src/network_freebsd_sendfile.c	2007-09-22 19:43:28.000000000 -0300
@@ -151,23 +151,23 @@
 			if (-1 == c->file.fd) {
 				if (-1 == (c->file.fd = open(c->file.name->ptr, O_RDONLY))) {
 					log_error_write(srv, __FILE__, __LINE__, "ss", "open failed: ", strerror(errno));
-
 					return -1;
 				}
-
 #ifdef FD_CLOEXEC
 				fcntl(c->file.fd, F_SETFD, FD_CLOEXEC);
 #endif
 			}
 
-			r = 0;
-
+eagain:
 			/* FreeBSD sendfile() */
+			r = 0;
 			if (-1 == sendfile(c->file.fd, fd, offset, toSend, NULL, &r, 0)) {
 				switch(errno) {
 				case EAGAIN:
+				case EINTR:
 					break;
 				case ENOTCONN:
+				case ENOTSOCK:
 					return -2;
 				default:
 					log_error_write(srv, __FILE__, __LINE__, "ssd", "sendfile: ", strerror(errno), errno);
@@ -190,12 +190,10 @@
 				if (offset >= sce->st.st_size) {
 					/* file shrinked, close the connection */
 					errno = oerrno;
-
 					return -1;
 				}
 
 				errno = oerrno;
-				return -2;
 			}
 
 			c->offset += r;
