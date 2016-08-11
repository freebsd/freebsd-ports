--- extensions/common/stack_frame.cc.orig	2016-05-11 19:02:22 UTC
+++ extensions/common/stack_frame.cc
@@ -7,7 +7,11 @@
 #include <string>
 
 #include "base/strings/utf_string_conversions.h"
+#if defined(OS_BSD)
+#include <re2/re2.h>
+#else
 #include "third_party/re2/src/re2/re2.h"
+#endif
 
 namespace extensions {
 
