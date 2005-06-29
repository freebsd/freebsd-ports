--- CZipReader.cpp.orig	Sun Sep 19 00:54:31 2004
+++ CZipReader.cpp	Sun Sep 19 00:54:53 2004
@@ -11,7 +11,7 @@
 #ifdef _WIN32
 #include "zlib\zlib.h"
 #else
-#include "zlib/zlib.h"
+#include <zlib.h>
 #endif // win32
 #endif // compile with zlib
 
