--- include/includes.h.orig	Fri Nov 26 00:47:28 2004
+++ include/includes.h	Fri Nov 26 01:59:16 2004
@@ -476,6 +476,14 @@
 #include <sys/xattr.h>
 #endif
 
+#ifdef HAVE_SYS_EXTATTR_H
+#include <sys/extattr.h>
+#endif
+
+#ifdef HAVE_SYS_UIO_H
+#include <sys/uio.h>
+#endif
+	     
 #if HAVE_LOCALE_H
 #include <locale.h>
 #endif
