--- resize.c.orig	Mon Sep  8 07:26:31 2003
+++ resize.c	Mon Dec  1 17:16:29 2003
@@ -682,6 +682,17 @@
   if (wi == 0)
     he = hi = 0;
 
+  if (wi > 1000)
+    {
+      Msg(0, "Window width too large, truncated");
+      wi = 1000;
+    }
+  if (he > 1000)
+    {
+      Msg(0, "Window height too large, truncated");
+      he = 1000;
+    }
+
   if (p->w_width == wi && p->w_height == he && p->w_histheight == hi)
     {
       debug("ChangeWindowSize: No change.\n");
