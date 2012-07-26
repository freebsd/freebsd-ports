--- memory/mozalloc/mozalloc.cpp~
+++ memory/mozalloc/mozalloc.cpp
@@ -19,6 +19,9 @@
 #if defined(XP_UNIX)
 #  include <unistd.h>           // for valloc on *BSD
 #endif //if defined(XP_UNIX)
+#ifdef __FreeBSD__
+#  include <malloc_np.h>        // for malloc_usable_size
+#endif
 
 #if defined(XP_WIN) || (defined(XP_OS2) && defined(__declspec))
 #  define MOZALLOC_EXPORT __declspec(dllexport)
@@ -210,7 +213,7 @@ moz_malloc_usable_size(void *ptr)
 
 #if defined(XP_MACOSX)
     return malloc_size(ptr);
-#elif defined(MOZ_MEMORY) || (defined(XP_LINUX) && !defined(ANDROID))
+#elif defined(MOZ_MEMORY) || (defined(XP_LINUX) && !defined(ANDROID)) || defined(__FreeBSD__)
     // Android bionic libc doesn't have malloc_usable_size.
     return malloc_usable_size(ptr);
 #elif defined(XP_WIN)
