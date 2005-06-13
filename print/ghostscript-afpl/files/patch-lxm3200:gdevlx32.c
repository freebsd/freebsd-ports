--- lxm3200/gdevlx32.c.orig	Wed Apr 23 01:06:20 2003
+++ lxm3200/gdevlx32.c	Thu May 26 00:11:50 2005
@@ -422,9 +422,11 @@
  * of the nearest color.
  */
 private gx_color_index
-lxm3200_map_rgb_color(gx_device *dev,	gx_color_value r, 
-											gx_color_value g, gx_color_value b)
+lxm3200_map_rgb_color(gx_device *dev,	const gx_color_value cv[]) 
 {
+	gx_color_value r = cv[0];
+	gx_color_value g = cv[1];
+	gx_color_value b = cv[2];
 	gx_color_index col;
 	int c, m, y;
 
@@ -479,7 +481,7 @@
 			break;
 
 		default:
-			col = gdev_prn_map_rgb_color(dev, r, g, b);
+			col = gdev_prn_map_rgb_color(dev, cv);
 			break;
 	}
 
@@ -732,10 +734,10 @@
 	/* Allocate memory for the buffers and
 	 * verify that the allocation was done properly.
 	 */
-	gendata.scanbuf = (byte *)gs_malloc(gendata.numbytes, gendata.numblines, 
+	gendata.scanbuf = (byte *)gs_malloc(pdev->memory, gendata.numbytes, gendata.numblines, 
 																			"lxm3200_print_page(scanbuf)");
 
-	gendata.outdata = (byte *)gs_malloc(gendata.numbytes, 30, 
+	gendata.outdata = (byte *)gs_malloc(pdev->memory, gendata.numbytes, 30, 
 																			"lxm3200_print_page(outdata)");
  
 	if(gendata.scanbuf == NULL || 
@@ -943,12 +945,14 @@
 private void
 freeresources(void)
 {
+	gx_device *pdev;
+
 	if(gendata.scanbuf)
-		gs_free((char *)gendata.scanbuf, gendata.numbytes, gendata.numblines,
+		gs_free(pdev->memory, (char *)gendata.scanbuf, gendata.numbytes, gendata.numblines,
 						"lxm3200:freeresources(scanbuf)");
 
 	if(gendata.outdata)
-		gs_free((char *)gendata.outdata, gendata.numbytes, 30, 
+		gs_free(pdev->memory, (char *)gendata.outdata, gendata.numbytes, 30, 
 						"lxm3200:freeresources(outdata)");
 }
 
