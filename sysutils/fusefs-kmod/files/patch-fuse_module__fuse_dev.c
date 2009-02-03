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
 
@@ -548,7 +553,12 @@
 	/* find any existing device, or allocate new unit number */
 	i = clone_create(&fuseclones, &fuse_cdevsw, &unit, dev, 0);
 	if (i) {
-		*dev = make_dev(&fuse_cdevsw, unit2minor(unit),
+		*dev = make_dev(&fuse_cdevsw,
+#if __FreeBSD_version < 800062
+				unit2minor(unit),
+#else /* __FreeBSD_version >= 800062 */
+				unit,
+#endif /* __FreeBSD_version < 800062 */
 			        UID_ROOT, GID_OPERATOR,
 		                S_IRUSR|S_IWUSR|S_IRGRP|S_IWGRP,
                                 "fuse%d", unit);
