--- src/3rdparty/chromium/gpu/command_buffer/service/program_manager.cc.orig	2023-11-09 11:32:20 UTC
+++ src/3rdparty/chromium/gpu/command_buffer/service/program_manager.cc
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
 
@@ -620,7 +624,7 @@ std::string Program::ProcessLogInfo(const std::string&
       output += hashed_name;
   }
 
-  return output + input.as_string();
+  return output + std::string(input);
 }
 
 void Program::UpdateLogInfo() {
