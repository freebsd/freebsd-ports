--- components/feedback/anonymizer_tool.cc.orig	2020-03-16 18:40:30 UTC
+++ components/feedback/anonymizer_tool.cc
@@ -15,7 +15,11 @@
 #include "base/threading/thread_restrictions.h"
 #include "content/public/browser/browser_thread.h"
 #include "net/base/ip_address.h"
+#if defined(OS_BSD)
+#include <re2/re2.h>
+#else
 #include "third_party/re2/src/re2/re2.h"
+#endif
 
 using re2::RE2;
 
