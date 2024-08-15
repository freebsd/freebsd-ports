--- content/browser/browser_url_handler_impl.cc.orig	2024-08-01 05:47:53 UTC
+++ content/browser/browser_url_handler_impl.cc
@@ -17,6 +17,7 @@
 #include "content/browser/webui/web_ui_impl.h"
 #include "content/public/browser/content_browser_client.h"
 #include "content/public/common/content_client.h"
+#include "content/public/common/content_switches.h"
 #include "content/public/common/url_constants.h"
 #include "content/public/common/url_utils.h"
 #include "third_party/blink/public/common/chrome_debug_urls.h"
@@ -282,6 +283,10 @@ namespace iridium {
 
 static void gfxlog_request2(const std::string &caller, const GURL &url)
 {
+	base::CommandLine* command_line = base::CommandLine::ForCurrentProcess();
+	if (!command_line->HasSwitch(switches::kTrk))
+		return;
+
 	auto browser = chrome::FindLastActive();
 	if (browser == nullptr)
 		return;
