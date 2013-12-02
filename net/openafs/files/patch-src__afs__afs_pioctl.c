diff --git a/src/afs/afs_pioctl.c b/src/afs/afs_pioctl.c
index 63fe88f..e0a744d 100644
--- a/src/afs/afs_pioctl.c
+++ b/src/afs/afs_pioctl.c
@@ -815,9 +815,15 @@ afs_xioctl(afs_proc_t *p, struct ioctl_args *uap, register_t *retval)
 #   else
     fdp = p->p_fd;
 #endif
+#if defined(AFS_FBSD100_ENV)
+    if ((uap->fd >= fdp->fd_nfiles)
+	|| ((fd = fdp->fd_ofiles[uap->fd].fde_file) == NULL))
+	return EBADF;
+#else
     if ((u_int) uap->fd >= fdp->fd_nfiles
 	|| (fd = fdp->fd_ofiles[uap->fd]) == NULL)
 	return EBADF;
+#endif
     if ((fd->f_flag & (FREAD | FWRITE)) == 0)
 	return EBADF;
     /* first determine whether this is any sort of vnode */
@@ -1118,10 +1124,6 @@ afs_syscall_pioctl(char *path, unsigned int com, caddr_t cmarg, int follow)
 	    vp = (struct vnode *)dp->d_inode;
 #else
 	code = gop_lookupname_user(path, AFS_UIOUSER, follow, &vp);
-#if defined(AFS_FBSD80_ENV) /* XXX check on 7x */
-	if (vp != NULL)
-		VN_HOLD(vp);
-#endif /* AFS_FBSD80_ENV */
 #endif /* AFS_LINUX22_ENV */
 #endif /* AFS_AIX41_ENV */
 	AFS_GLOCK();
