--- content/browser/gpu/gpu_internals_ui.cc.orig	2016-07-22 00:06:54.000000000 -0400
+++ content/browser/gpu/gpu_internals_ui.cc	2016-08-03 12:29:59.399353000 -0400
@@ -39,7 +39,7 @@
 #include "third_party/angle/src/common/version.h"
 #include "ui/gl/gpu_switching_manager.h"
 
-#if defined(OS_LINUX) && defined(USE_X11)
+#if (defined(OS_BSD) || defined(OS_LINUX)) && defined(USE_X11)
 #include <X11/Xlib.h>
 #endif
 #if defined(OS_WIN)
@@ -47,7 +47,7 @@
 #include "ui/gfx/win/physical_size.h"
 #endif
 
-#if defined(OS_LINUX) && defined(USE_X11)
+#if (defined(OS_BSD) || defined(OS_LINUX)) && defined(USE_X11)
 #include "ui/base/x/x11_util.h"       // nogncheck
 #include "ui/gfx/x/x11_atom_cache.h"  // nogncheck
 #endif
@@ -200,7 +200,7 @@
                                              gpu_info.gl_ws_version));
   basic_info->Append(NewDescriptionValuePair("Window system binding extensions",
                                              gpu_info.gl_ws_extensions));
-#if defined(OS_LINUX) && defined(USE_X11)
+#if (defined(OS_BSD) || defined(OS_LINUX)) && defined(USE_X11)
   basic_info->Append(NewDescriptionValuePair("Window manager",
                                              ui::GuessWindowManagerName()));
   {
