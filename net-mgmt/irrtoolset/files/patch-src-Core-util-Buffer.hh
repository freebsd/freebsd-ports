--- src/Core/util/Buffer.hh.orig	2004-07-30 12:58:10.000000000 +0200
+++ src/Core/util/Buffer.hh
@@ -30,7 +30,11 @@
 
 #include <cstdlib>
 #include <cstring>
+#if (__GNUC__ > 2)
 #include <ostream>
+#else
+#include <ostream.h>
+#endif
 extern "C" {
 #ifdef HAVE_MALLOC_H
 #include <malloc.h>
