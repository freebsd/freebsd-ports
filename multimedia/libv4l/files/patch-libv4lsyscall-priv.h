--- libv4lconvert/libv4lsyscall-priv.h	2010-01-09 23:33:01.000000000 +0100
+++ libv4lconvert/libv4lsyscall-priv.h	2010-01-09 23:33:24.000000000 +0100
@@ -84,7 +84,7 @@
 #define SYS_WRITE(fd, buf, len) \
     syscall(SYS_write, (int)(fd), (void *)(buf), (size_t)(len));
 #define SYS_MMAP(addr, len, prot, flags, fd, off) \
-    syscall(SYS_mmap2, (void *)(addr), (size_t)(len), \
+    __syscall(SYS_mmap2, (void *)(addr), (size_t)(len), \
 	(int)(prot), (int)(flags), (int)(fd), (__off_t)((off) >> MMAP2_PAGE_SHIFT))
 #define SYS_MUNMAP(addr, len) \
     syscall(SYS_munmap, (void *)(addr), (size_t)(len))
