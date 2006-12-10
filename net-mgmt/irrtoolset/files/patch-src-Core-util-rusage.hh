--- src/Core/util/rusage.hh.orig	2004-07-30 12:58:10.000000000 +0200
+++ src/Core/util/rusage.hh
@@ -56,7 +56,11 @@
 #define RUSAGE_H
 
 #include "config.h"
+#if (__GNUC__ > 2)
 #include <ostream>
+#else
+#include <ostream.h>
+#endif
 
 class Rusage {
 private:
