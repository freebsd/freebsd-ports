--- src/common/compat/fcntl.h.orig	2016-11-29 22:48:37 UTC
+++ src/common/compat/fcntl.h
@@ -22,11 +22,15 @@
 #include <errno.h>
 #include <sys/types.h>
 
-#if (defined(__FreeBSD__) || defined(__CYGWIN__))
+#if ((defined(__FreeBSD__) && __FreeBSD__ < 11) || defined(__CYGWIN__))
 typedef long long off64_t;
 #endif
 
-#if (defined(__FreeBSD__) || defined(__sun__))
+#if defined(__FreeBSD__)
+typedef off_t loff_t;
+#endif
+
+#if defined(__sun__)
 typedef off64_t loff_t;
 #endif
 
@@ -69,15 +73,6 @@ static inline ssize_t splice(int fd_in, 
 }
 #endif
 
-#ifdef __FreeBSD__
-#define POSIX_FADV_DONTNEED 0
-
-static inline int posix_fadvise(int fd, off_t offset, off_t len, int advice)
-{
-	return -ENOSYS;
-}
-#endif
-
 #if !(defined(__linux__) || defined(__FreeBSD__) || defined(__CYGWIN__) || defined(__sun__) || defined(__APPLE__))
 #error "Please add support for your OS."
 #endif /* __linux__ , __FreeBSD__, __CYGWIN__, __sun__, __APPLE__ */
