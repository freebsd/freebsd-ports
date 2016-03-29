--- extensions/common/stack_frame.cc.orig	2016-03-05 21:29:12.679508172 +0100
+++ extensions/common/stack_frame.cc	2016-03-05 21:29:26.039507364 +0100
@@ -7,7 +7,11 @@
 #include <string>
 
 #include "base/strings/utf_string_conversions.h"
+#if defined(OS_BSD)
+#include <re2/re2.h>
+#else
 #include "third_party/re2/src/re2/re2.h"
+#endif
 
 namespace extensions {
 
