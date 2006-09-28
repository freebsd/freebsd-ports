--- fuse_module/fuse_subr.c.orig	Fri Feb 10 17:31:53 2006
+++ fuse_module/fuse_subr.c	Wed Sep 27 11:57:01 2006
@@ -15,9 +15,11 @@
 {
 	int err;
 	int unprivileged_proc_debug;
+	size_t ilen = sizeof(unprivileged_proc_debug);
 
 	err = kernel_sysctlbyname(td, "security.bsd.unprivileged_proc_debug",
-		NULL, 0, &unprivileged_proc_debug, sizeof(unprivileged_proc_debug), NULL, 0);
+		&unprivileged_proc_debug, &ilen,
+		NULL, 0, NULL, 0);
 
 	if (err)
 		unprivileged_proc_debug = 0;
