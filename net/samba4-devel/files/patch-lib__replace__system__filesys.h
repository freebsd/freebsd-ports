--- ./lib/replace/system/filesys.h.orig	2010-01-11 05:35:28.000000000 +0000
+++ ./lib/replace/system/filesys.h	2010-01-24 21:49:26.000000000 +0000
@@ -117,6 +117,13 @@
 #include <sys/xattr.h>
 #endif
 
+#if HAVE_SYS_EXTATTR_H
+#include <sys/extattr.h>
+#endif
+
+#if HAVE_SYS_UIO_H
+#include <sys/uio.h>
+#endif
 
 #ifdef HAVE_SYS_RESOURCE_H
 #include <sys/resource.h>
