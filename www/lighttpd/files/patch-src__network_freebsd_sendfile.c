#
# Backport http://redmine.lighttpd.net/issues/show/1913
#
--- src/network_freebsd_sendfile.c.orig	2009-02-05 09:41:44.000000000 -0200
+++ src/network_freebsd_sendfile.c	2009-02-24 15:11:29.000000000 -0300
@@ -167,8 +167,9 @@
 				switch(errno) {
 				case EAGAIN:
 				case EINTR:
-					r = 0; /* try again later */
-					break;
+					/* for EAGAIN/EINTR r still contains the sent bytes */
+					break; /* try again later */
+				case EPIPE:
 				case ENOTCONN:
 					return -2;
 				default:

