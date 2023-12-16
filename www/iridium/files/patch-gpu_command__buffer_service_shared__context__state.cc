--- gpu/command_buffer/service/shared_context_state.cc.orig	2023-11-22 14:00:11 UTC
+++ gpu/command_buffer/service/shared_context_state.cc
@@ -4,6 +4,7 @@
 
 #include "gpu/command_buffer/service/shared_context_state.h"
 
+#include "base/immediate_crash.h"
 #include "base/observer_list.h"
 #include "base/strings/stringprintf.h"
 #include "base/system/sys_info.h"
@@ -101,6 +102,13 @@ void SharedContextState::compileError(const char* shad
                << "------------------------\n"
                << shader << "\nErrors:\n"
                << errors;
+
+    // Increase shader cache shm count and crash the GPU process so that the
+    // browser process would clear the cache.
+    GpuProcessShmCount::ScopedIncrement increment(
+        use_shader_cache_shm_count_.get());
+
+    base::ImmediateCrash();
   }
 }
 
@@ -305,6 +313,7 @@ bool SharedContextState::InitializeGanesh(
     gl::ProgressReporter* progress_reporter) {
   progress_reporter_ = progress_reporter;
   gr_shader_cache_ = cache;
+  use_shader_cache_shm_count_ = use_shader_cache_shm_count;
 
   size_t max_resource_cache_bytes;
   size_t glyph_cache_max_texture_bytes;
