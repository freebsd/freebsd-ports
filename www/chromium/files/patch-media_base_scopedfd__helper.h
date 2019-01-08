--- media/base/scopedfd_helper.h.orig	2018-12-12 22:56:08.000000000 +0100
+++ media/base/scopedfd_helper.h	2018-12-16 13:21:03.268137000 +0100
@@ -14,14 +14,14 @@
 // since the only current user is V4L2 we are limiting the scope to OS_LINUX so
 // the binary size does not inflate on non-using systems. Feel free to adapt
 // this and BUILD.gn as our needs evolve.
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 
 // Return a new vector containing duplicates of |fds|, or an empty vector in
 // case of error.
 MEDIA_EXPORT std::vector<base::ScopedFD> DuplicateFDs(
     const std::vector<base::ScopedFD>& fds);
 
-#endif  // OS_LINUX
+#endif  // OS_LINUX || OS_BSD
 
 }  // namespace media
 
