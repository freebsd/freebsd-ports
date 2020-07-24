--- media/base/scopedfd_helper.h.orig	2019-09-09 21:55:20 UTC
+++ media/base/scopedfd_helper.h
@@ -11,17 +11,17 @@
 namespace media {
 
 // Theoretically, we can test on defined(OS_POSIX) || defined(OS_FUCHSIA), but
-// since the only current user is V4L2 we are limiting the scope to OS_LINUX so
+// since the only current user is V4L2 we are limiting the scope to OS_LINUX || OS_BSD so
 // the binary size does not inflate on non-using systems. Feel free to adapt
 // this and BUILD.gn as our needs evolve.
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 
 // Return a new vector containing duplicates of |fds|, or PCHECKs in case of an
 // error.
 MEDIA_EXPORT std::vector<base::ScopedFD> DuplicateFDs(
     const std::vector<base::ScopedFD>& fds);
 
-#endif  // OS_LINUX
+#endif  // OS_LINUX || OS_BSD
 
 }  // namespace media
 
