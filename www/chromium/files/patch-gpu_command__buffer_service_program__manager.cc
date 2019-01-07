--- gpu/command_buffer/service/program_manager.cc.orig	2018-12-03 21:16:59.000000000 +0100
+++ gpu/command_buffer/service/program_manager.cc	2018-12-13 23:16:40.689817000 +0100
@@ -30,7 +30,11 @@
 #include "gpu/command_buffer/service/program_cache.h"
 #include "gpu/command_buffer/service/shader_manager.h"
 #include "gpu/config/gpu_preferences.h"
+#if defined(OS_BSD)
+#include <re2/re2.h>
+#else
 #include "third_party/re2/src/re2/re2.h"
+#endif
 #include "ui/gl/gl_version_info.h"
 #include "ui/gl/progress_reporter.h"
 
