--- ../generic/tclPort.h.orig	2013-09-03 14:47:31.000000000 +0200
+++ ../generic/tclPort.h	2013-09-04 10:23:22.000000000 +0200
@@ -20,7 +20,7 @@
 #if defined(_WIN32)
 #   include "tclWinPort.h"
 #else
-#   include "tclUnixPort.h"
+#   include "../unix/tclUnixPort.h"
 #endif
 #include "tcl.h"
 
