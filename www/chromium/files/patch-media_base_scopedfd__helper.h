--- media/base/scopedfd_helper.h.orig	2019-03-11 22:00:59 UTC
+++ media/base/scopedfd_helper.h
@@ -14,14 +14,14 @@ namespace media {
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
 
