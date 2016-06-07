--- gpu/command_buffer/service/program_manager.cc.orig	2016-05-11 19:02:23 UTC
+++ gpu/command_buffer/service/program_manager.cc
@@ -29,7 +29,11 @@
 #include "gpu/command_buffer/service/gpu_switches.h"
 #include "gpu/command_buffer/service/program_cache.h"
 #include "gpu/command_buffer/service/shader_manager.h"
+#if defined(OS_BSD)
+#include <re2/re2.h>
+#else
 #include "third_party/re2/src/re2/re2.h"
+#endif
 #include "ui/gl/gl_version_info.h"
 
 using base::TimeDelta;
