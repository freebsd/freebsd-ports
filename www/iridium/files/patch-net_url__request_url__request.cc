--- net/url_request/url_request.cc.orig	2024-08-01 05:47:53 UTC
+++ net/url_request/url_request.cc
@@ -10,6 +10,7 @@
 #	include <unistd.h>
 #endif
 
+#include "base/command_line.h"
 #include "base/compiler_specific.h"
 #include "base/functional/bind.h"
 #include "base/functional/callback.h"
@@ -21,6 +22,7 @@
 #include "base/task/single_thread_task_runner.h"
 #include "base/types/pass_key.h"
 #include "base/values.h"
+#include "content/public/common/content_switches.h"
 #include "net/base/auth.h"
 #include "net/base/features.h"
 #include "net/base/io_buffer.h"
@@ -58,7 +60,10 @@ namespace iridium {
 
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
