#
# fix security hole in non-chroot rsync daemon
#  <http://lists.samba.org/archive/rsync-announce/2004/000017.html>
#
--- orig/util.c	2004-04-27 12:59:37 -0700
+++ util.c	2004-08-11 23:37:27 -0700
@@ -743,7 +743,7 @@
 				allowdotdot = 1;
 			} else {
 				p += 2;
-				if (*p == '/')
+				while (*p == '/')
 					p++;
 				if (sanp != start) {
 					/* back up sanp one level */
