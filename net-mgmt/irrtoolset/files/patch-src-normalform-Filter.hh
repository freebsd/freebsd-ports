--- src/normalform/Filter.hh.orig	2004-07-30 12:58:12.000000000 +0200
+++ src/normalform/Filter.hh
@@ -55,7 +55,11 @@
 #define FILTER_H
 
 #include "config.h"
+#if (__GNUC__ > 2)
 #include <ostream>
+#else
+#include <ostream.h>
+#endif
 extern "C" {
 #include <sys/types.h>
 }
