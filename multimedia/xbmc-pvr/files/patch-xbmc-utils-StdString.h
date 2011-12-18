--- xbmc/utils/StdString.h.orig
+++ xbmc/utils/StdString.h
@@ -2,6 +2,7 @@
 #include <string>
 #include <stdint.h>
 #include <vector>
+#include <cstring>
 
 #if defined(_WIN32) && !defined(va_copy)
 #define va_copy(dst, src) ((dst) = (src))
