--- ui/gl/gl_surface_glx.cc.orig	2019-05-28 10:26:51.705074000 +0200
+++ ui/gl/gl_surface_glx.cc	2019-05-28 10:44:19.461809000 +0200
@@ -21,6 +21,7 @@
 #include "base/time/time.h"
 #include "base/trace_event/trace_event.h"
 #include "build/build_config.h"
+#include "ui/base/x/x11_util.h"
 #include "ui/events/platform/platform_event_source.h"
 #include "ui/gfx/x/x11.h"
 #include "ui/gfx/x/x11_connection.h"
@@ -431,7 +432,9 @@
   }
 
   const XVisualInfo& visual_info =
-      gl::GLVisualPickerGLX::GetInstance()->rgba_visual();
+      ui::IsCompositingManagerPresent()
+          ? gl::GLVisualPickerGLX::GetInstance()->rgba_visual()
+          : gl::GLVisualPickerGLX::GetInstance()->system_visual();
   g_visual = visual_info.visual;
   g_depth = visual_info.depth;
   g_colormap =
@@ -581,18 +584,30 @@
   }
   size_ = gfx::Size(attributes.width, attributes.height);
 
-  XSetWindowAttributes swa;
-  memset(&swa, 0, sizeof(swa));
-  swa.background_pixmap = 0;
-  swa.bit_gravity = NorthWestGravity;
-  swa.colormap = g_colormap;
-  swa.background_pixel = 0;
-  swa.border_pixel = 0;
-  window_ = XCreateWindow(
-      gfx::GetXDisplay(), parent_window_, 0 /* x */, 0 /* y */, size_.width(),
-      size_.height(), 0 /* border_width */, g_depth, InputOutput, g_visual,
-      CWBackPixmap | CWBitGravity | CWColormap | CWBackPixel | CWBorderPixel,
-      &swa);
+  XSetWindowAttributes swa = {
+      .background_pixmap = 0,
+      .bit_gravity = NorthWestGravity,
+      .colormap = g_colormap,
+      .background_pixel = 0, // ARGB(0,0,0,0) for compositing WM
+      .border_pixel = 0,
+  };
+  auto value_mask = CWBackPixmap | CWBitGravity | CWColormap | CWBorderPixel;
+  if (ui::IsCompositingManagerPresent() &&
+      XVisualIDFromVisual(attributes.visual) == XVisualIDFromVisual(g_visual)) {
+    // When parent and child are using the same visual, the back buffer will be
+    // shared between parent and child. If WM compositing is enabled, we set
+    // child's background pixel to ARGB(0,0,0,0), so ARGB(0,0,0,0) will be
+    // filled to the shared buffer, when the child window is mapped. It can
+    // avoid an annoying flash when the child window is mapped below.
+    // If WM compositing is disabled, we don't set the background pixel, so
+    // nothing will be draw when the child window is mapped.
+    value_mask |= CWBackPixel;
+  }
+
+  window_ =
+      XCreateWindow(gfx::GetXDisplay(), parent_window_, 0 /* x */, 0 /* y */,
+                    size_.width(), size_.height(), 0 /* border_width */,
+                    g_depth, InputOutput, g_visual, value_mask, &swa);
   if (!window_) {
     LOG(ERROR) << "XCreateWindow failed";
     return false;
