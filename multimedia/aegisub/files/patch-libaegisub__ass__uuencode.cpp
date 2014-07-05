--- libaegisub/ass/uuencode.cpp.orig
+++ libaegisub/ass/uuencode.cpp
@@ -16,6 +16,8 @@
 
 #include "../config.h"
 
+#include <cstring>
+
 #include "libaegisub/ass/uuencode.h"
 
 // Despite being called uuencoding by ass_specs.doc, the format is actually
