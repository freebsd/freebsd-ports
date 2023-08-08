--- chrome/test/chromedriver/chrome/client_hints.h.orig	2023-07-24 14:27:53 UTC
+++ chrome/test/chromedriver/chrome/client_hints.h
@@ -7,6 +7,7 @@
 
 #include <third_party/abseil-cpp/absl/types/optional.h>
 #include <string>
+#include <vector>
 
 struct BrandVersion {
   // Browser brand.
