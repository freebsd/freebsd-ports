--- src/gdevsgi.c.orig	Fri Feb 22 07:24:52 2002
+++ src/gdevsgi.c	Sun Nov 10 22:55:30 2002
@@ -32,8 +32,11 @@
   sgi_prn_device(sgi_procs, "sgirgb", 3, 24, 255, 255, sgi_print_page);
 
 private gx_color_index
-sgi_map_rgb_color(gx_device *dev, ushort r, ushort g, ushort b)
-{      ushort bitspercolor = dev->color_info.depth / 3;
+sgi_map_rgb_color(gx_device *dev, const ushort cv[])
+{      ushort r = cv[0];
+       ushort g = cv[1];
+       ushort b = cv[2];
+       ushort bitspercolor = dev->color_info.depth / 3;
        ulong max_value = (1 << bitspercolor) - 1;
        return ((r*max_value / gx_max_color_value) << (bitspercolor * 2)) +
 	      ((g*max_value / gx_max_color_value) << bitspercolor) +
