--- fuse_module/fuse_dev.c
+++ fuse_module/fuse_dev.c
@@ -52,8 +52,13 @@
 	.d_read = fusedev_read,
 	.d_write = fusedev_write,
 	.d_version = D_VERSION,
+#ifndef D_NEEDMINOR
+#define D_NEEDMINOR 0
+#endif
 #if ! DO_GIANT_MANUALLY
-	.d_flags = D_NEEDGIANT,
+	.d_flags = D_NEEDMINOR|D_NEEDGIANT,
+#else
+	.d_flags = D_NEEDMINOR,
 #endif
 };
 
