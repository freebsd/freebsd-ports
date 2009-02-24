#
# Backport http://redmine.lighttpd.net/projects/lighttpd/repository/revisions/2403
#
--- src/network_freebsd_sendfile.c.orig	2009-02-24 11:05:06.000000000 -0300
+++ src/network_freebsd_sendfile.c	2009-02-24 11:12:15.000000000 -0300
@@ -167,7 +167,7 @@
 				switch(errno) {
 				case EAGAIN:
 				case EINTR:
-					r = 0; /* try again later */
+					/* for EAGAIN and EINTR r still contains the sent bytes */
 					break;
 				case ENOTCONN:
 					return -2;
