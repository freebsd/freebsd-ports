--- include/grub/util/libzfs.h.orig
+++ include/grub/util/libzfs.h
@@ -22,6 +22,9 @@
 #include <config.h>
 
 #ifdef HAVE_LIBZFS_H
+#ifdef __FreeBSD__
+typedef int boolean_t;
+#endif
 #include <libzfs.h>
 #else /* ! HAVE_LIBZFS_H */
 
