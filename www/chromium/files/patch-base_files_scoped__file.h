--- base/files/scoped_file.h.orig	2021-07-28 07:19:23 UTC
+++ base/files/scoped_file.h
@@ -26,7 +26,7 @@ struct BASE_EXPORT ScopedFDCloseTraits : public Scoped
   static void Release(const ScopedGeneric<int, ScopedFDCloseTraits>&, int);
 };
 #elif defined(OS_POSIX) || defined(OS_FUCHSIA)
-#if defined(OS_CHROMEOS) || defined(OS_LINUX)
+#if defined(OS_CHROMEOS) || defined(OS_LINUX) || defined(OS_BSD)
 // On ChromeOS and Linux we guard FD lifetime with a global table and hook into
 // libc close() to perform checks.
 struct BASE_EXPORT ScopedFDCloseTraits : public ScopedGenericOwnershipTracking {
@@ -37,7 +37,7 @@ struct BASE_EXPORT ScopedFDCloseTraits {
     return -1;
   }
   static void Free(int fd);
-#if defined(OS_CHROMEOS) || defined(OS_LINUX)
+#if defined(OS_CHROMEOS) || defined(OS_LINUX) || defined(OS_BSD)
   static void Acquire(const ScopedGeneric<int, ScopedFDCloseTraits>&, int);
   static void Release(const ScopedGeneric<int, ScopedFDCloseTraits>&, int);
 #endif
@@ -54,7 +54,7 @@ struct ScopedFILECloser {
 
 }  // namespace internal
 
-#if defined(OS_CHROMEOS) || defined(OS_LINUX)
+#if defined(OS_CHROMEOS) || defined(OS_LINUX) || defined(OS_BSD)
 namespace subtle {
 
 // Enables or disables enforcement of FD ownership as tracked by ScopedFD
@@ -104,11 +104,11 @@ typedef ScopedGeneric<int, internal::ScopedFDCloseTrai
 // Automatically closes |FILE*|s.
 typedef std::unique_ptr<FILE, internal::ScopedFILECloser> ScopedFILE;
 
-#if defined(OS_CHROMEOS) || defined(OS_LINUX)
+#if defined(OS_CHROMEOS) || defined(OS_LINUX) || defined(OS_BSD)
 // Queries the ownership status of an FD, i.e. whether it is currently owned by
 // a ScopedFD in the calling process.
 bool BASE_EXPORT IsFDOwned(int fd);
-#endif  // defined(OS_CHROMEOS) || defined(OS_LINUX)
+#endif  // defined(OS_CHROMEOS) || defined(OS_LINUX) || defined(OS_BSD)
 
 }  // namespace base
 
