--- base/containers/checked_iterators_unittest.cc.orig	2021-10-05 14:50:27 UTC
+++ base/containers/checked_iterators_unittest.cc
@@ -88,7 +88,7 @@ TEST(CheckedContiguousIterator, ConvertingComparisonOp
 // lags a bit behind.
 // TODO(crbug.com/1166360): Enable this test on ChromeOS once the shared libc++
 // is sufficiently modern.
-#if defined(_LIBCPP_VERSION) && !defined(OS_NACL) && !defined(OS_CHROMEOS)
+#if defined(_LIBCPP_VERSION) && !defined(OS_NACL) && !defined(OS_CHROMEOS) && !defined(OS_BSD)
 namespace {
 
 // Helper template that wraps an iterator and disables its dereference and
