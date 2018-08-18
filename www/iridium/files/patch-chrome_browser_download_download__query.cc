--- chrome/browser/download/download_query.cc.orig	2018-06-13 00:10:05.000000000 +0200
+++ chrome/browser/download/download_query.cc	2018-07-15 13:01:15.987418000 +0200
@@ -27,7 +27,11 @@
 #include "components/download/public/common/download_item.h"
 #include "components/url_formatter/url_formatter.h"
 #include "content/public/browser/content_browser_client.h"
+#if defined(OS_BSD)
+#include <re2/re2.h>
+#else
 #include "third_party/re2/src/re2/re2.h"
+#endif
 #include "url/gurl.h"
 
 using download::DownloadDangerType;
