--- net/url_request/url_request.cc.orig	2026-05-11 13:57:04 UTC
+++ net/url_request/url_request.cc
@@ -10,6 +10,7 @@
 #	include <unistd.h>
 #endif
 
+#include "base/command_line.h"
 #include "base/compiler_specific.h"
 #include "base/functional/bind.h"
 #include "base/functional/callback.h"
@@ -25,6 +26,7 @@
 #include "base/types/optional_util.h"
 #include "base/types/pass_key.h"
 #include "base/values.h"
+#include "content/public/common/content_switches.h"
 #include "net/base/auth.h"
 #include "net/base/features.h"
 #include "net/base/io_buffer.h"
@@ -67,7 +69,10 @@ namespace iridium {
 
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
