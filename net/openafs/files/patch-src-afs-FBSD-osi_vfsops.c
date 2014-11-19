--- src/afs/FBSD/osi_vfsops.c.orig	2014-11-08 11:45:02.000000000 +0900
+++ src/afs/FBSD/osi_vfsops.c	2014-11-08 12:01:34.000000000 +0900
@@ -49,7 +49,11 @@
     int code;
     int offset = AFS_SYSCALL;
 #if defined(AFS_FBSD90_ENV) || defined(AFS_FBSD82_ENV)
+# if defined(FBSD_SYSCALL_REGISTER_FOUR_ARGS)
+    code = syscall_register(&offset, &afs_sysent, &old_sysent, 0);
+# else
     code = syscall_register(&offset, &afs_sysent, &old_sysent);
+# endif
     if (code) {
 	printf("AFS_SYSCALL in use, error %i. aborting\n", code);
 	return code;
