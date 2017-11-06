--- components/drive/drive_api_util.cc.orig	2017-04-19 19:06:32 UTC
+++ components/drive/drive_api_util.cc
@@ -22,7 +22,11 @@
 #include "google_apis/drive/drive_api_parser.h"
 #include "net/base/escape.h"
 #include "net/base/net_errors.h"
+#if defined(OS_BSD)
+#include <re2/re2.h>
+#else
 #include "third_party/re2/src/re2/re2.h"
+#endif
 #include "url/gurl.h"
 
 namespace drive {
