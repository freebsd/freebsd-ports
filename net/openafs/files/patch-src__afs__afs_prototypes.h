diff --git a/src/afs/afs_prototypes.h b/src/afs/afs_prototypes.h
index 04f13ad..4135ebb 100644
--- a/src/afs/afs_prototypes.h
+++ b/src/afs/afs_prototypes.h
@@ -935,8 +935,9 @@ extern int copyin_afs_ioctl(caddr_t cmarg, struct afs_ioctl *dst);
 #if defined(AFS_DARWIN_ENV) || defined(AFS_XBSD_ENV)
 #ifdef AFS_DARWIN100_ENV
 extern int afs3_syscall(afs_proc_t *p, void *args, unsigned int *retval);
-#elif defined(AFS_FBSD90_ENV) || defined(AFS_FBSD82_ENV)
-/* afs3_syscall prototype is in sys/sysproto.h */
+#elif (defined(AFS_FBSD90_ENV) || defined(AFS_FBSD82_ENV)) && (__FreeBSD_version < 900044)
+/* afs3_syscall prototype is in sys/sysproto.h
+   Yes, they put it in, then took it out again (renamed with a sys_ prefix) */
 #elif defined(AFS_FBSD_ENV)
 extern int afs3_syscall(struct thread *p, void *args);
 #elif defined(AFS_NBSD50_ENV)
