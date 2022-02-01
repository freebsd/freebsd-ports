--- media/base/scopedfd_helper.h.orig	2021-12-14 11:45:07 UTC
+++ media/base/scopedfd_helper.h
@@ -15,14 +15,14 @@ namespace media {
 // since the only current user is V4L2 we are limiting the scope to OS_LINUX so
 // the binary size does not inflate on non-using systems. Feel free to adapt
 // this and BUILD.gn as our needs evolve.
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 
 // Return a new vector containing duplicates of |fds|, or PCHECKs in case of an
 // error.
 MEDIA_EXPORT std::vector<base::ScopedFD> DuplicateFDs(
     const std::vector<base::ScopedFD>& fds);
 
-#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS)
+#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 
 }  // namespace media
 
