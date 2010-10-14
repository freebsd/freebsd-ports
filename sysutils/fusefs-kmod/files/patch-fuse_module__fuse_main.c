--- fuse_module/fuse_main.c.00	2010-08-15 14:40:29.000000000 +0400
+++ fuse_module/fuse_main.c	2010-08-15 15:56:56.000000000 +0400
@@ -108,6 +108,9 @@
 	switch (what) {
 	case MOD_LOAD:                /* kldload */
 
+#if __FreeBSD_version > 800009
+	        fuse_fileops.fo_truncate = vnops.fo_truncate;
+#endif
 		fuse_fileops.fo_ioctl    = vnops.fo_ioctl;
 		fuse_fileops.fo_poll     = vnops.fo_poll;
 		fuse_fileops.fo_kqfilter = vnops.fo_kqfilter;


