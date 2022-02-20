--- base/strings/string_util.cc.orig	2022-02-07 13:39:41 UTC
+++ base/strings/string_util.cc
@@ -36,7 +36,7 @@ namespace base {
 bool IsWprintfFormatPortable(const wchar_t* format) {
   // This snippet of code checks that we can build C++17 code.
   // TODO(thakis): Enable this on all platforms, and then remove it again.
-#if !defined(OS_LINUX) && !BUILDFLAG(CFI_ICALL_CHECK) && \
+#if !defined(OS_LINUX) && !defined(OS_BSD) && !BUILDFLAG(CFI_ICALL_CHECK) && \
     !BUILDFLAG(CFI_CAST_CHECK)
   if constexpr (constexpr int i = 0; i > 0) {
   }
