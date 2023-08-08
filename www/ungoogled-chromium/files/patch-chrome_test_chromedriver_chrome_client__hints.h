--- chrome/test/chromedriver/chrome/client_hints.h.orig	2023-07-21 09:49:17 UTC
+++ chrome/test/chromedriver/chrome/client_hints.h
@@ -7,6 +7,7 @@
 
 #include <third_party/abseil-cpp/absl/types/optional.h>
 #include <string>
+#include <vector>
 
 struct BrandVersion {
   // Browser brand.
