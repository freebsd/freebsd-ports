--- components/feedback/anonymizer_tool.cc.orig	2016-05-11 19:02:18 UTC
+++ components/feedback/anonymizer_tool.cc
@@ -9,7 +9,11 @@
 #include "base/strings/string_number_conversions.h"
 #include "base/strings/string_util.h"
 #include "base/strings/stringprintf.h"
+#if defined(OS_BSD)
+#include <re2/re2.h>
+#else
 #include "third_party/re2/src/re2/re2.h"
+#endif
 
 using re2::RE2;
 
