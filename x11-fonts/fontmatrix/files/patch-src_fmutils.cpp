--- src/fmutils.cpp.orig	2019-04-29 07:46:55 UTC
+++ src/fmutils.cpp
@@ -12,7 +12,7 @@
 
 #include "fmutils.h"
 
-#if !defined(_WIN32) && !defined(Q_OS_MAC)
+#if !defined(_WIN32) && !defined(Q_OS_MAC) && !defined(__FreeBSD__)
 #include <execinfo.h>
 #include <cxxabi.h>
 #include <cstdlib>
@@ -68,4 +68,4 @@ void printBacktrace ( int frames )
 }
 
 
-#endif
\ No newline at end of file
+#endif
