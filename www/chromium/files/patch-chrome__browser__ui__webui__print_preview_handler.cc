--- chrome/browser/ui/webui/print_preview_handler.cc.orig    2011-09-30 03:01:50.000000000 -0500
+++ chrome/browser/ui/webui/print_preview_handler.cc       2011-10-06 00:48:39.943195565 -0500
@@ -46,6 +46,7 @@
 
 #if defined(USE_CUPS)
 #include <cups/cups.h>
+#include <cups/ppd.h>
 
 #include "base/file_util.h"
 #endif
