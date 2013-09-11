--- Tools/DumpRenderTree/gtk/DumpRenderTree.cpp.orig	2012-08-20 18:26:18.000000000 +0200
+++ Tools/DumpRenderTree/gtk/DumpRenderTree.cpp	2013-09-11 12:28:29.000000000 +0200
@@ -48,6 +48,7 @@
 #include "WorkQueueItem.h"
 #include <JavaScriptCore/JavaScript.h>
 #include <cassert>
+#include <clocale>
 #include <cstdlib>
 #include <cstring>
 #include <getopt.h>
