--- ../generic/tclPort.h.orig	2010-02-01 00:51:36.000000000 +0100
+++ ../generic/tclPort.h	2010-09-17 16:28:05.133598753 +0200
@@ -24,7 +24,7 @@
 #endif
 #include "tcl.h"
 #if !defined(_WIN32)
-#   include "tclUnixPort.h"
+#   include "../unix/tclUnixPort.h"
 #endif
 
 #if defined(__CYGWIN__)
