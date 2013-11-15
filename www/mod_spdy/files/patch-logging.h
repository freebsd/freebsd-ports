--- third_party/chromium/src/base/logging.h.org 2013-10-29 15:17:59.000000000 +0900
+++ third_party/chromium/src/base/logging.h     2013-10-29 23:39:25.000000000 +0900
@@ -5,6 +5,8 @@
 #ifndef BASE_LOGGING_H_
 #define BASE_LOGGING_H_

+#undef strtoul
+
 #include <cassert>
 #include <string>
 #include <cstring>
