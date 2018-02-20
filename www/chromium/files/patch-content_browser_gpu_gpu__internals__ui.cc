--- content/browser/gpu/gpu_internals_ui.cc.orig	2017-12-15 02:04:16.000000000 +0100
+++ content/browser/gpu/gpu_internals_ui.cc	2017-12-24 12:40:09.587854000 +0100
@@ -51,7 +51,7 @@
 #include "ui/gfx/win/physical_size.h"
 #endif
 
-#if defined(OS_LINUX) && defined(USE_X11)
+#if (defined(OS_BSD) || defined(OS_LINUX)) && defined(USE_X11)
 #include "ui/base/x/x11_util.h"       // nogncheck
 #include "ui/gfx/x/x11_atom_cache.h"  // nogncheck
 #endif
@@ -209,7 +209,7 @@
                                              gpu_info.gl_ws_version));
   basic_info->Append(NewDescriptionValuePair("Window system binding extensions",
                                              gpu_info.gl_ws_extensions));
-#if defined(OS_LINUX) && defined(USE_X11)
+#if (defined(OS_BSD) || defined(OS_LINUX)) && defined(USE_X11)
   basic_info->Append(NewDescriptionValuePair("Window manager",
                                              ui::GuessWindowManagerName()));
   {
