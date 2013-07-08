--- ../generic/tclPort.h.orig	2013-04-03 16:57:25.000000000 +0200
+++ ../generic/tclPort.h	2013-04-03 16:57:35.000000000 +0200
@@ -20,7 +20,7 @@
 #if defined(_WIN32)
 #   include "tclWinPort.h"
 #else
-#   include "tclUnixPort.h"
+#   include "../unix/tclUnixPort.h"
 #endif
 #include "tcl.h"
