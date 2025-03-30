- https://github.com/snl-dakota/dakota/pull/181

--- src/WorkdirHelper.cpp.orig	2025-03-30 08:18:38 UTC
+++ src/WorkdirHelper.cpp
@@ -11,6 +11,7 @@
 #include "dakota_data_util.hpp"  // for strcontains
 #include "dakota_global_defs.hpp"
 #include <boost/array.hpp>
+#include <boost/filesystem/exception.hpp>
 #include <boost/tokenizer.hpp>
 #include <cassert>
 
