--- src/gdevcp50.c.orig	Fri Feb 22 07:24:51 2002
+++ src/gdevcp50.c	Sun Nov 10 22:35:13 2002
@@ -204,9 +204,12 @@
  
 /* Map a r-g-b color to a color index. */
 private gx_color_index
-cp50_rgb_color(gx_device *dev, gx_color_value r, gx_color_value g,
-  gx_color_value b)
-{   return ((ulong)gx_color_value_to_byte(r) << 16)+
+cp50_rgb_color(gx_device *dev, const gx_color_value cv[])
+{
+    gx_color_value r = cv[0];
+    gx_color_value g = cv[1];
+    gx_color_value b = cv[2];
+    return ((ulong)gx_color_value_to_byte(r) << 16)+
            ((uint)gx_color_value_to_byte(g) << 8) +
            gx_color_value_to_byte(b);
 }
