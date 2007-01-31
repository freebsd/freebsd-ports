--- ../generic/tclPort.h.orig	Tue Jan 30 11:39:50 2007
+++ ../generic/tclPort.h	Tue Jan 30 11:41:05 2007
@@ -24,7 +24,7 @@
 #if defined(__WIN32__)
 #   include "../win/tclWinPort.h"
 #else
-#   include "tclUnixPort.h"
+#   include "../unix/tclUnixPort.h"
 #endif
 
 #if !defined(LLONG_MIN)
