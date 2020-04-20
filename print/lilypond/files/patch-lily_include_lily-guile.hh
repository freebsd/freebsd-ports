--- lily/include/lily-guile.hh.orig	2020-02-04 16:12:57 UTC
+++ lily/include/lily-guile.hh
@@ -22,6 +22,8 @@
 
 #include "config.hh"
 
+#include <cstddef>
+
 #if __MINGW32__
 #include "mingw-compatibility.hh"
 #endif
