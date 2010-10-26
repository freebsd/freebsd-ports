--- ./lib/replace/system/filesys.h.orig	2010-10-07 18:41:16.000000000 +0200
+++ ./lib/replace/system/filesys.h	2010-10-26 01:52:57.000000000 +0200
@@ -53,6 +53,10 @@
 #include <acl/libacl.h>
 #endif
 
+#ifdef HAVE_SUNACL_H
+#include <sunacl.h>
+#endif
+
 #ifdef HAVE_SYS_FS_S5PARAM_H
 #include <sys/fs/s5param.h>
 #endif
