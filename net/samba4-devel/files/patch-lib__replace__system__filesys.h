--- ./lib/replace/system/filesys.h.orig	2009-06-19 04:36:48.000000000 +0000
+++ ./lib/replace/system/filesys.h	2009-07-12 02:39:36.000000000 +0000
@@ -53,23 +53,23 @@
 #include <acl/libacl.h>
 #endif
 
-#ifdef HAVE_SYS_FS_S5PARAM_H 
+#ifdef HAVE_SYS_FS_S5PARAM_H
 #include <sys/fs/s5param.h>
 #endif
 
 #if defined (HAVE_SYS_FILSYS_H) && !defined (_CRAY)
-#include <sys/filsys.h> 
+#include <sys/filsys.h>
 #endif
 
 #ifdef HAVE_SYS_STATFS_H
 # include <sys/statfs.h>
 #endif
 
-#ifdef HAVE_DUSTAT_H              
+#ifdef HAVE_DUSTAT_H
 #include <sys/dustat.h>
 #endif
 
-#ifdef HAVE_SYS_STATVFS_H          
+#ifdef HAVE_SYS_STATVFS_H
 #include <sys/statvfs.h>
 #endif
 
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
