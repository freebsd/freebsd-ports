-- Guard basename() with #if defined(__linux__) since it is only used in
-- Linux-specific code. Without this, clang emits -Werror,-Wunneeded-internal-declaration
-- on FreeBSD, causing a build failure.
--- third_party/kineto/libkineto/src/ThreadUtil.cpp.orig	2026-05-16 05:59:15 UTC
+++ third_party/kineto/libkineto/src/ThreadUtil.cpp
@@ -130,11 +130,13 @@ constexpr size_t kMaxThreadNameLength = 16;
 namespace {
 constexpr size_t kMaxThreadNameLength = 16;
 
+#if defined(__linux__)
 constexpr const char* basename(const char* s, int off = 0) {
   return !s[off]      ? s
       : s[off] == '/' ? basename(&s[off + 1])
                       : basename(s, off + 1);
 }
+#endif
 #if defined(_WIN32)
 void* getKernel32Func(const char* procName) {
   return reinterpret_cast<void*>(
