--- libglusterfs/src/glusterfs/syscall.h.orig	2020-08-04 12:41:32 UTC
+++ libglusterfs/src/glusterfs/syscall.h
@@ -266,4 +266,13 @@ ssize_t
 sys_copy_file_range(int fd_in, off64_t *off_in, int fd_out, off64_t *off_out,
                     size_t len, unsigned int flags);
 
+int
+sys_kill(pid_t pid, int sig);
+
+#ifdef __FreeBSD__
+int
+sys_sysctl(const int *name, u_int namelen, void *oldp,	size_t *oldlenp,
+		 const void *newp, size_t newlen);
+#endif
+
 #endif /* __SYSCALL_H__ */
