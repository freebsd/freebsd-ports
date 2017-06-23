--- content/browser/gpu/gpu_internals_ui.cc.orig	2017-06-05 19:03:07 UTC
+++ content/browser/gpu/gpu_internals_ui.cc
@@ -43,7 +43,7 @@
 #include "third_party/skia/include/core/SkMilestone.h"
 #include "ui/gl/gpu_switching_manager.h"
 
-#if defined(OS_LINUX) && defined(USE_X11)
+#if (defined(OS_BSD) || defined(OS_LINUX)) && defined(USE_X11)
 #include <X11/Xlib.h>
 #endif
 #if defined(OS_WIN)
@@ -51,7 +51,7 @@
 #include "ui/gfx/win/physical_size.h"
 #endif
 
-#if defined(OS_LINUX) && defined(USE_X11)
+#if (defined(OS_BSD) || defined(OS_LINUX)) && defined(USE_X11)
 #include "ui/base/x/x11_util.h"       // nogncheck
 #include "ui/gfx/x/x11_atom_cache.h"  // nogncheck
 #endif
@@ -206,7 +206,7 @@ base::DictionaryValue* GpuInfoAsDictionaryValue() {
                                              gpu_info.gl_ws_version));
   basic_info->Append(NewDescriptionValuePair("Window system binding extensions",
                                              gpu_info.gl_ws_extensions));
-#if defined(OS_LINUX) && defined(USE_X11)
+#if (defined(OS_BSD) || defined(OS_LINUX)) && defined(USE_X11)
   basic_info->Append(NewDescriptionValuePair("Window manager",
                                              ui::GuessWindowManagerName()));
   {
