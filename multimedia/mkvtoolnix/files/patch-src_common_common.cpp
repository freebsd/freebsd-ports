--- src/common/common.cpp.orig	2015-07-18 11:39:41 UTC
+++ src/common/common.cpp
@@ -33,6 +33,10 @@
 #include "common/strings/editing.h"
 #include "common/translation.h"
 
+#ifdef HAVE_UNISTD_H
+#include <unistd.h>
+#endif
+
 #if !defined(LIBMATROSKA_VERSION) || (LIBMATROSKA_VERSION <= 0x000801)
 #define matroska_init()
 #define matroska_done()
