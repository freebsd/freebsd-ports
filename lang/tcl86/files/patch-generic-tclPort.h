--- generic/tclPort.h.orig	2016-02-25 20:12:37 UTC
+++ generic/tclPort.h
@@ -20,7 +20,7 @@
 #if defined(_WIN32)
 #   include "tclWinPort.h"
 #else
-#   include "tclUnixPort.h"
+#   include "../unix/tclUnixPort.h"
 #endif
 #include "tcl.h"
 
