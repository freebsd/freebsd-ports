--- components/feedback/anonymizer_tool.cc.orig	2018-03-20 23:05:22.000000000 +0100
+++ components/feedback/anonymizer_tool.cc	2018-03-24 13:39:35.199314000 +0100
@@ -11,7 +11,11 @@
 #include "base/strings/string_util.h"
 #include "base/strings/stringprintf.h"
 #include "content/public/browser/browser_thread.h"
+#if defined(OS_BSD)
+#include <re2/re2.h>
+#else
 #include "third_party/re2/src/re2/re2.h"
+#endif
 
 using re2::RE2;
 
