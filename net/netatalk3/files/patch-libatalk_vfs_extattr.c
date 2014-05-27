--- libatalk/vfs/extattr.c.orig	2013-10-18 07:57:33.000000000 -0400
+++ libatalk/vfs/extattr.c	2014-05-27 12:31:57.000000000 -0400
@@ -193,6 +193,8 @@ ssize_t sys_fgetxattr (int filedes, cons
     const char *attrname = ((s=strchr(name, '.')) == NULL) ? name : s + 1;
 
     if((retval=extattr_get_fd(filedes, attrnamespace, attrname, NULL, 0)) >= 0) {
+	if (size == 0)
+	    return retval;
         if(retval > size) {
             errno = ERANGE;
             return -1;
@@ -241,6 +243,10 @@ ssize_t sys_lgetxattr (const char *path,
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
