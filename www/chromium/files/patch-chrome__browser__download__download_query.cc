--- chrome/browser/download/download_query.cc.orig	2016-03-05 21:04:25.551612729 +0100
+++ chrome/browser/download/download_query.cc	2016-03-05 21:05:14.895785377 +0100
@@ -31,7 +31,11 @@
 #include "components/url_formatter/url_formatter.h"
 #include "content/public/browser/content_browser_client.h"
 #include "content/public/browser/download_item.h"
+#if defined(OS_BSD)
+#include <re2/re2.h>
+#else
 #include "third_party/re2/src/re2/re2.h"
+#endif
 #include "url/gurl.h"
 
 using content::DownloadDangerType;
