--- ../generic/tclPort.h.orig	2012-06-26 15:59:02.000000000 +0200
+++ ../generic/tclPort.h	2012-09-17 16:29:41.000000000 +0200
@@ -22,7 +22,7 @@
 #endif
 #include "tcl.h"
 #if !defined(_WIN32)
-#   include "tclUnixPort.h"
+#   include "../unix/tclUnixPort.h"
 #endif
 
 #if !defined(LLONG_MIN)
