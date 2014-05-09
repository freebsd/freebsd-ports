--- libatalk/vfs/extattr.c.orig	2014-05-09 13:42:40.000000000 -0400
+++ libatalk/vfs/extattr.c	2014-05-09 13:45:39.000000000 -0400
@@ -241,6 +241,10 @@ ssize_t sys_lgetxattr (const char *path,
 #elif defined(HAVE_EXTATTR_GET_LINK)
 	ssize_t retval;
 	if((retval=extattr_get_link(path, EXTATTR_NAMESPACE_USER, uname, NULL, 0)) >= 0) {
+		if (size == 0) {
+			/* size == 0 means only return size */
+			return retval;
+		}
 		if(retval > size) {
 			errno = ERANGE;
 			return -1;
