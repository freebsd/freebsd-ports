--- src/3rdparty/chromium/third_party/perfetto/src/trace_processor/db/column/numeric_storage.cc.orig	2024-02-25 20:08:06 UTC
+++ src/3rdparty/chromium/third_party/perfetto/src/trace_processor/db/column/numeric_storage.cc
@@ -39,7 +39,11 @@ namespace trace_processor {
 namespace column {
 namespace {
 
+#if (defined(__OpenBSD__) || defined(__FreeBSD__)) && defined(__i386__)
+using NumericValue = std::variant<uint32_t, int32_t, int64_t, double>;
+#else
 using NumericValue = std::variant<uint32_t, int32_t, int64_t, double_t>;
+#endif
 
 // Using the fact that binary operators in std are operators() of classes, we
 // can wrap those classes in variants and use them for std::visit in

