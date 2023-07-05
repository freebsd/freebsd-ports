--- os.h.orig	2023-07-05 18:10:28 UTC
+++ os.h
@@ -40,7 +40,7 @@
 #endif // COMP_MINGW || COMP_MSC
 
 #if !defined(COMP_CYGWIN)
-#include <stdint.h>
+#include <inttypes.h>
 #endif // !COMP_CYGWIN
 
 #if defined(SYS_WINDOWS)
