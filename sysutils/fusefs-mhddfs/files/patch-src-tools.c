--- src/tools.c.orig	2010-01-11 15:48:46.000000000 +0300
+++ src/tools.c	2010-01-11 15:53:42.000000000 +0300
@@ -30,7 +30,10 @@
 #include <fcntl.h>
 #include <sys/types.h>
 #include <dirent.h>
+
+#ifndef WITHOUT_XATTR
 #include <attr/xattr.h>
+#endif
 
 #include "tools.h"
 #include "debug.h"
@@ -262,11 +265,13 @@
 	ftime.modtime = st.st_mtime;
 	utime(to, &ftime);
 
+#ifndef WITHOUT_XATTR
         // extended attributes
         if (copy_xattrs(from, to) == -1)
             mhdd_debug(MHDD_MSG,
                     "copy_xattrs: error copying xattrs from %s to %s\n",
                     from, to);
+#endif
 
 
 	from = strdup(from);
@@ -282,6 +287,7 @@
 	return ret;
 }
 
+#ifndef WITHOUT_XATTR
 int copy_xattrs(const char *from, const char *to)
 {
         int listsize=0, attrvalsize=0;
@@ -350,6 +356,7 @@
         free(listbuf);
         return 0;
 }
+#endif
 
 char * create_path(const char *dir, const char * file)
 {
@@ -465,11 +472,13 @@
 			strerror(errno));
 	}
 
+#ifndef WITHOUT_XATTR
         // copy extended attributes of parent dir
         if (copy_xattrs(exists, path_parent) == -1)
             mhdd_debug(MHDD_MSG,
                     "copy_xattrs: error copying xattrs from %s to %s\n",
                     exists, path_parent);
+#endif
 
 	free(exists);
 	free(path_parent);
