--- net/instaweb/rewriter/image.cc.orig	2017-09-13 23:22:49 UTC
+++ net/instaweb/rewriter/image.cc
@@ -20,6 +20,7 @@
 
 #include <algorithm>
 #include <cstddef>
+#include <zlib.h>
 
 #include "base/logging.h"
 #include "net/instaweb/rewriter/cached_result.pb.h"
