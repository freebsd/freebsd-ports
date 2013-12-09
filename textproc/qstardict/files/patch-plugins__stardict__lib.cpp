--- ./plugins/stardict/lib.cpp.orig	2011-12-05 12:40:49.000000000 +0000
+++ ./plugins/stardict/lib.cpp	2013-12-09 11:22:18.738921230 +0000
@@ -9,6 +9,7 @@
 #include <sys/stat.h>
 #include <zlib.h>
 #include <glib/gstdio.h>
+#include <stdlib.h>
 
 #include "distance.h"
 #include "file.hpp"
