--- ../generic/tclPort.h.orig	2011-04-26 17:14:03.000000000 +0200
+++ ../generic/tclPort.h	2011-08-09 14:25:40.620587462 +0200
@@ -22,7 +22,7 @@
 #endif
 #include "tcl.h"
 #if !defined(_WIN32)
-#   include "tclUnixPort.h"
+#   include "../unix/tclUnixPort.h"
 #endif
 
 #if defined(__CYGWIN__)
