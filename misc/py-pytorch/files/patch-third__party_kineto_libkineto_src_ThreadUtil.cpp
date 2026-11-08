-- Guard basename() with #ifdef __linux__ since it is only called from Linux-specific
-- code; without the guard Clang emits -Wunneeded-internal-declaration treated as error.
--- third_party/kineto/libkineto/src/ThreadUtil.cpp.orig	2026-10-28 18:15:59 UTC
+++ third_party/kineto/libkineto/src/ThreadUtil.cpp
@@ -132,11 +132,13 @@ constexpr size_t kMaxThreadNameLength = 16;
 namespace {
 constexpr size_t kMaxThreadNameLength = 16;
 
+#ifdef __linux__
 constexpr const char* basename(const char* s, int off = 0) {
   return !s[off]      ? s
       : s[off] == '/' ? basename(&s[off + 1])
                       : basename(s, off + 1);
 }
+#endif
 #if defined(_WIN32)
 void* getKernel32Func(const char* procName) {
   return reinterpret_cast<void*>(
