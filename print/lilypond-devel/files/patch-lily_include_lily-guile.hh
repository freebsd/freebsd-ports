--- lily/include/lily-guile.hh.orig	2016-08-30 10:23:53 UTC
+++ lily/include/lily-guile.hh
@@ -20,6 +20,8 @@
 #ifndef LILY_GUILE_HH
 #define LILY_GUILE_HH
 
+#include <cstddef>
+
 #if __MINGW32__
 #include "mingw-compatibility.hh"
 #endif
