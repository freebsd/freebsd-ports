commit 57b30241311091b5a6a5a0bb1c19a8e073860fc3
Author: Christoph Moench-Tegeder <cmt@burggraben.net>

    do not assert on alignment when not having the bits
    
    the underlying issue seemed to be win-only anyways?

diff --git js/public/Utility.h js/public/Utility.h
index 0d745e9df785..f0ca7ea37162 100644
--- js/public/Utility.h
+++ js/public/Utility.h
@@ -480,6 +480,7 @@ static inline void js_free(void* p) {
  * Note: Do not add a ; at the end of a use of JS_DECLARE_NEW_METHODS,
  * or the build will break.
  */
+#if !defined(__i386__)
 #define JS_DECLARE_NEW_METHODS(NEWNAME, ALLOCATOR, QUALIFIERS)              \
   template <class T, typename... Args>                                      \
   QUALIFIERS T* MOZ_HEAP_ALLOCATOR NEWNAME(Args&&... args) {                \
@@ -490,6 +491,15 @@ static inline void js_free(void* p) {
     return MOZ_LIKELY(memory) ? new (memory) T(std::forward<Args>(args)...) \
                               : nullptr;                                    \
   }
+#else
+#define JS_DECLARE_NEW_METHODS(NEWNAME, ALLOCATOR, QUALIFIERS)              \
+  template <class T, typename... Args>                                      \
+  QUALIFIERS T* MOZ_HEAP_ALLOCATOR NEWNAME(Args&&... args) {                \
+    void* memory = ALLOCATOR(sizeof(T));                                    \
+    return MOZ_LIKELY(memory) ? new (memory) T(std::forward<Args>(args)...) \
+                              : nullptr;                                    \
+  }
+#endif
 
 /*
  * Given a class which should provide a 'new' method that takes an arena as
