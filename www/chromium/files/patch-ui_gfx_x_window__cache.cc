--- ui/gfx/x/window_cache.cc.orig	2022-05-19 14:06:27 UTC
+++ ui/gfx/x/window_cache.cc
@@ -152,13 +152,13 @@ Window WindowCache::GetWindowAtPoint(gfx::Point point_
     }
   }
 
-  if (info->has_wm_name)
-    return window;
   for (Window child : base::Reversed(info->children)) {
     Window ret = GetWindowAtPoint(point_px, child, ignore);
     if (ret != Window::None)
       return ret;
   }
+  if (info->has_wm_name)
+    return window;
   return Window::None;
 }
 
