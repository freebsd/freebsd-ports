--- third_party/perfetto/src/base/test/vm_test_utils.cc.orig	2021-07-28 09:44:38 UTC
+++ third_party/perfetto/src/base/test/vm_test_utils.cc
@@ -97,7 +97,7 @@ bool IsMapped(void* start, size_t size) {
   ignore_result(page_size);
   return true;
 #else
-#if PERFETTO_BUILDFLAG(PERFETTO_OS_APPLE)
+#if PERFETTO_BUILDFLAG(PERFETTO_OS_APPLE) || PERFETTO_BUILDFLAG(PERFETTO_OS_FREEBSD)
   using PageState = char;
   static constexpr PageState kIncoreMask = MINCORE_INCORE;
 #else
