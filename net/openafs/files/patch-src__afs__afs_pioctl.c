diff --git a/src/afs/afs_pioctl.c b/src/afs/afs_pioctl.c
index cf432d6..2589b79 100644
--- a/src/afs/afs_pioctl.c
+++ b/src/afs/afs_pioctl.c
@@ -874,7 +874,11 @@ afs_xioctl(afs_proc_t *p, const struct ioctl_args *uap, register_t *retval)
 
     if (!ioctlDone) {
 # if defined(AFS_FBSD_ENV)
+#  if (__FreeBSD_version >= 900044)
+	return sys_ioctl(td, uap);
+#  else
 	return ioctl(td, uap);
+#  endif
 # elif defined(AFS_OBSD_ENV)
 	code = sys_ioctl(p, uap, retval);
 # elif defined(AFS_NBSD_ENV)
