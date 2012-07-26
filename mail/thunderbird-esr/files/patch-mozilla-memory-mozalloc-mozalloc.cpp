--- mozilla/memory/mozalloc/mozalloc.cpp~
+++ mozilla/memory/mozalloc/mozalloc.cpp
@@ -52,6 +52,9 @@
 #if defined(XP_UNIX)
 #  include <unistd.h>           // for valloc on *BSD
 #endif //if defined(XP_UNIX)
+#ifdef __FreeBSD__
+#  include <malloc_np.h>        // for malloc_usable_size
+#endif
 
 #if defined(MOZ_MEMORY)
 // jemalloc.h doesn't redeclare symbols if they're provided by the OS
@@ -259,7 +262,7 @@ moz_malloc_usable_size(void *ptr)
 
 #if defined(XP_MACOSX)
     return malloc_size(ptr);
-#elif defined(MOZ_MEMORY)
+#elif defined(MOZ_MEMORY) || defined(__FreeBSD__)
     return malloc_usable_size(ptr);
 #elif defined(XP_WIN)
     return _msize(ptr);
