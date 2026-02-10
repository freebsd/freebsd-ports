--- src/3rdparty/chromium/base/metrics/histogram_macros.h.orig	2025-04-23 16:00:55 UTC
+++ src/3rdparty/chromium/base/metrics/histogram_macros.h
@@ -54,13 +54,14 @@
 //
 // The second variant requires three arguments: the first two are the same as
 // before, and the third argument is the enum boundary: this must be strictly
-// greater than any other enumerator that will be sampled.
+// greater than any other enumerator that will be sampled. This only works for
+// enums with a fixed underlying type.
 //
 // Sample usage:
 //   // These values are logged to UMA. Entries should not be renumbered and
 //   // numeric values should never be reused. Please keep in sync with "MyEnum"
 //   // in src/tools/metrics/histograms/enums.xml.
-//   enum class MyEnum {
+//   enum class MyEnum : uint8_t {
 //     FIRST_VALUE = 0,
 //     SECOND_VALUE = 1,
 //     ...
