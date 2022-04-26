--- net/url_request/url_request.cc.orig	2022-04-01 07:48:30 UTC
+++ net/url_request/url_request.cc
@@ -14,12 +14,14 @@
 #include "base/callback.h"
 #include "base/callback_helpers.h"
 #include "base/compiler_specific.h"
+#include "base/command_line.h"
 #include "base/metrics/histogram_macros.h"
 #include "base/rand_util.h"
 #include "base/strings/utf_string_conversions.h"
 #include "base/synchronization/lock.h"
 #include "base/threading/thread_task_runner_handle.h"
 #include "base/values.h"
+#include "content/public/common/content_switches.h"
 #include "net/base/auth.h"
 #include "net/base/load_flags.h"
 #include "net/base/load_timing_info.h"
@@ -57,7 +59,10 @@ namespace iridium {
 
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
