--- net/url_request/url_request.cc.orig	2023-01-17 19:19:00 UTC
+++ net/url_request/url_request.cc
@@ -13,6 +13,7 @@
 #include "base/bind.h"
 #include "base/callback.h"
 #include "base/callback_helpers.h"
+#include "base/command_line.h"
 #include "base/compiler_specific.h"
 #include "base/metrics/histogram_macros.h"
 #include "base/rand_util.h"
@@ -20,6 +21,7 @@
 #include "base/synchronization/lock.h"
 #include "base/threading/thread_task_runner_handle.h"
 #include "base/values.h"
+#include "content/public/common/content_switches.h"
 #include "net/base/auth.h"
 #include "net/base/load_flags.h"
 #include "net/base/load_timing_info.h"
@@ -54,7 +56,10 @@ namespace iridium {
 
 void textlog_request(const char *caller, const GURL &url)
 {
-#ifdef __linux__
+	base::CommandLine* command_line = base::CommandLine::ForCurrentProcess();
+	if (!command_line->HasSwitch(switches::kTrk))
+		return;
+#ifdef __unix__
 	bool tty = isatty(fileno(stderr));
 #else
 	bool tty = false;
