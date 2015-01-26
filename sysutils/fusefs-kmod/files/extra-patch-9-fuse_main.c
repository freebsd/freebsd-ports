--- fs/fuse/fuse_main.c.orig	2014-12-02 15:57:14.465629906 +0200
+++ fs/fuse/fuse_main.c	2014-12-02 16:03:10.070605830 +0200
@@ -92,10 +92,19 @@
 	.vfc_flags = VFCF_SYNTHETIC
 };
 
+#ifdef SYSCTL_NULL_INT_PTR
+SYSCTL_INT(_vfs_fuse, OID_AUTO, kernelabi_major, CTLFLAG_RD,
+    SYSCTL_NULL_INT_PTR, FUSE_KERNEL_VERSION,
+    "FUSE kernel abi major version");
+SYSCTL_INT(_vfs_fuse, OID_AUTO, kernelabi_minor, CTLFLAG_RD,
+    SYSCTL_NULL_INT_PTR, FUSE_KERNEL_MINOR_VERSION,
+    "FUSE kernel abi minor version");
+#else
 SYSCTL_INT(_vfs_fuse, OID_AUTO, kernelabi_major, CTLFLAG_RD,
     0, FUSE_KERNEL_VERSION, "FUSE kernel abi major version");
 SYSCTL_INT(_vfs_fuse, OID_AUTO, kernelabi_minor, CTLFLAG_RD,
     0, FUSE_KERNEL_MINOR_VERSION, "FUSE kernel abi minor version");
+#endif // SYSCTL_NULL_INT_PTR
 
 /******************************
  *
