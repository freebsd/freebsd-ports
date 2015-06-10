--- src/common/common.cpp.orig	2015-06-08 16:28:17.092399114 +0200
+++ src/common/common.cpp	2015-06-08 16:28:32.292398239 +0200
@@ -30,6 +30,10 @@
 #include "common/strings/editing.h"
 #include "common/translation.h"
 
+#ifdef HAVE_UNISTD_H
+#include <unistd.h>
+#endif
+
 #if !defined(LIBMATROSKA_VERSION) || (LIBMATROSKA_VERSION <= 0x000801)
 #define matroska_init()
 #define matroska_done()
