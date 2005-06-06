-- pcl3/eprn/eprnrend.c.orig	2005-01-19 00:24:24.924311968 +0100
+++ pcl3/eprn/eprnrend.c	2005-01-19 01:24:06.024901928 +0100
@@ -161,8 +161,10 @@
 ******************************************************************************/
 
 gx_color_index eprn_map_rgb_color_for_RGB(gx_device *device,
-  gx_color_value red, gx_color_value green, gx_color_value blue)
+  const gx_color_value cv[])
 {
+  gx_color_value red, green, blue;
+  red = cv[0]; green = cv[1]; blue = cv[2];
   static const gx_color_value half = gx_max_color_value/2;
   gx_color_index value = 0;
   const eprn_Device *dev = (eprn_Device *)device;
@@ -197,8 +199,10 @@
 ******************************************************************************/
 
 gx_color_index eprn_map_rgb_color_for_CMY_or_K(gx_device *device,
-  gx_color_value red, gx_color_value green, gx_color_value blue)
+  const gx_color_value cv[])
 {
+  gx_color_value red, green, blue;
+  red = cv[0]; green = cv[1]; blue = cv[2];
   static const gx_color_value half = gx_max_color_value/2;
   gx_color_index value = (CYAN_BIT | MAGENTA_BIT | YELLOW_BIT);
   const eprn_Device *dev = (eprn_Device *)device;
@@ -240,8 +244,10 @@
 ******************************************************************************/
 
 gx_color_index eprn_map_rgb_color_for_RGB_flex(gx_device *device,
-  gx_color_value red, gx_color_value green, gx_color_value blue)
+  const gx_color_value cv[])
 {
+  gx_color_value red, green, blue;
+  red = cv[0]; green = cv[1]; blue = cv[2];
   gx_color_index value = 0;
   gx_color_value step;
   unsigned int level;
@@ -284,8 +290,10 @@
 ******************************************************************************/
 
 gx_color_index eprn_map_rgb_color_for_CMY_or_K_flex(gx_device *device,
-  gx_color_value red, gx_color_value green, gx_color_value blue)
+  const gx_color_value cv[])
 {
+  gx_color_value red, green, blue;
+  red = cv[0]; green = cv[1]; blue = cv[2];
   const eprn_Device *dev = (eprn_Device *)device;
 
 #ifdef EPRN_TRACE
@@ -298,11 +306,18 @@
   /* Treat pure grey levels differently if we have black. This implies that for
      CMY+K only "true" grey shades will be printed with black ink, all others
      will be mixed from CMY. */
-  if (dev->eprn.colour_model != eprn_DeviceCMY && red == green && green == blue)
-    return eprn_map_cmyk_color_flex(device, 0, 0, 0, gx_max_color_value - red);
+  gx_color_value tmpcv[4];
+  if (dev->eprn.colour_model != eprn_DeviceCMY && red == green && green == blue) {
+    tmpcv[0] = 0; tmpcv[1] = 0; tmpcv[2] = 0;
+    tmpcv[3] = gx_max_color_value - red;
+    return eprn_map_cmyk_color_flex(device, tmpcv);
 
-  return eprn_map_cmyk_color_flex(device, gx_max_color_value - red,
-    gx_max_color_value - green, gx_max_color_value - blue, 0);
+  }
+  tmpcv[0] = gx_max_color_value - red; 
+  tmpcv[1] = gx_max_color_value - green; 
+  tmpcv[2] = gx_max_color_value - blue; 
+  tmpcv[3] = 0;
+  return eprn_map_cmyk_color_flex(device, tmpcv);
 }
 
 /******************************************************************************
@@ -315,8 +330,10 @@
 ******************************************************************************/
 
 gx_color_index eprn_map_rgb_color_for_RGB_max(gx_device *device,
-  gx_color_value red, gx_color_value green, gx_color_value blue)
+  const gx_color_value cv[])
 {
+  gx_color_value red, green, blue;
+  red = cv[0]; green = cv[1]; blue = cv[2];
   gx_color_index value;
 
 #ifdef EPRN_TRACE
@@ -345,8 +362,10 @@
 ******************************************************************************/
 
 gx_color_index eprn_map_rgb_color_for_CMY_or_K_max(gx_device *device,
-  gx_color_value red, gx_color_value green, gx_color_value blue)
+  const gx_color_value cv[])
 {
+  gx_color_value red, green, blue;
+  red = cv[0]; green = cv[1]; blue = cv[2];
   const eprn_Device *dev = (eprn_Device *)device;
 
 #ifdef EPRN_TRACE
@@ -356,13 +375,19 @@
     red, green, blue);
 #endif
 
-  if (dev->eprn.colour_model == eprn_DeviceGray)
-    return eprn_map_cmyk_color_max(device, 0, 0, 0, gx_max_color_value - red);
-
+  gx_color_value tmpcv[4];
+  if (dev->eprn.colour_model == eprn_DeviceGray) {
+    tmpcv[0] = 0; tmpcv[1] = 0; tmpcv[2] = 0;
+    tmpcv[3] = gx_max_color_value - red;
+    return eprn_map_cmyk_color_max(device, tmpcv);
+  }
   /* Note that the conversion from composite black to true black for CMY+K can
      only happen at the output pixel level, not here. */
-  return eprn_map_cmyk_color_max(device, gx_max_color_value - red,
-    gx_max_color_value - green, gx_max_color_value - blue, 0);
+  tmpcv[0] = gx_max_color_value - red; 
+  tmpcv[1] = gx_max_color_value - green; 
+  tmpcv[2] = gx_max_color_value - blue; 
+  tmpcv[3] = 0;
+  return eprn_map_cmyk_color_max(device, tmpcv);
 }
 
 /******************************************************************************
@@ -389,7 +414,7 @@
 ******************************************************************************/
 
 int eprn_map_color_rgb(gx_device *device, gx_color_index color,
-  gx_color_value rgb[3])
+  gx_color_value rgb[])
 {
 #ifdef EPRN_TRACE
   if_debug1(EPRN_TRACE_CHAR,
@@ -415,9 +440,10 @@
 ******************************************************************************/
 
 gx_color_index eprn_map_cmyk_color(gx_device *device,
-  gx_color_value cyan, gx_color_value magenta, gx_color_value yellow,
-  gx_color_value black)
+  const gx_color_value cv[])
 {
+  gx_color_value cyan, magenta, yellow, black;
+  cyan = cv[0]; magenta = cv[1]; yellow = cv[2]; black = cv[3];
   gx_color_index value = 0;
   static const gx_color_value threshold = gx_max_color_value/2;
 
@@ -449,9 +475,10 @@
 ******************************************************************************/
 
 gx_color_index eprn_map_cmyk_color_flex(gx_device *device,
-  gx_color_value cyan, gx_color_value magenta, gx_color_value yellow,
-  gx_color_value black)
+  const gx_color_value cv[])
 {
+  gx_color_value cyan, magenta, yellow, black;
+  cyan = cv[0]; magenta = cv[1]; yellow = cv[2]; black = cv[3];
   gx_color_index value = 0;
   gx_color_value step;
   unsigned int level;
@@ -530,9 +557,10 @@
 ******************************************************************************/
 
 gx_color_index eprn_map_cmyk_color_max(gx_device *device,
-  gx_color_value cyan, gx_color_value magenta, gx_color_value yellow,
-  gx_color_value black)
+  const gx_color_value cv[])
 {
+  gx_color_value cyan, magenta, yellow, black;
+  cyan = cv[0]; magenta = cv[1]; yellow = cv[2]; black = cv[3];
   gx_color_index value;
 
 #ifdef EPRN_TRACE
