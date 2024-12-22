--- services/video_effects/video_effects_sandbox_hook_linux.cc.orig	2024-12-22 12:24:29 UTC
+++ services/video_effects/video_effects_sandbox_hook_linux.cc
@@ -6,7 +6,13 @@
 
 #include <dlfcn.h>
 
+#include "build/build_config.h"
+
+#if BUILDFLAG(IS_BSD)
+#include "sandbox/policy/sandbox.h"
+#else
 #include "sandbox/policy/linux/sandbox_linux.h"
+#endif
 #include "services/on_device_model/ml/chrome_ml.h"
 
 namespace video_effects {
@@ -29,8 +35,10 @@ bool VideoEffectsPreSandboxHook(
     DVLOG(1) << "Successfully opened Chrome ML shared library.";
   }
 
+#if !BUILDFLAG(IS_BSD)
   auto* instance = sandbox::policy::SandboxLinux::GetInstance();
   instance->EngageNamespaceSandboxIfPossible();
+#endif
   return true;
 }
 
