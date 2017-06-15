--- plugins/stardict/lib.cpp.orig	2011-12-05 12:40:49 UTC
+++ plugins/stardict/lib.cpp
@@ -9,6 +9,7 @@
 #include <sys/stat.h>
 #include <zlib.h>
 #include <glib/gstdio.h>
+#include <stdlib.h>
 
 #include "distance.h"
 #include "file.hpp"
