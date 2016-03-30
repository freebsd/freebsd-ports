--- gpu/command_buffer/service/program_manager.cc.orig	2016-03-05 21:34:10.137487636 +0100
+++ gpu/command_buffer/service/program_manager.cc	2016-03-05 21:35:00.089484564 +0100
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
