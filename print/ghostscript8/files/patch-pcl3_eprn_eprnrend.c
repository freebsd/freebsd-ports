--- pcl3/eprn/eprnrend.c.orig	Wed Aug  1 14:12:56 2001
+++ pcl3/eprn/eprnrend.c	Tue May 24 20:19:18 2005
@@ -161,8 +161,11 @@
 ******************************************************************************/
 
 gx_color_index eprn_map_rgb_color_for_RGB(gx_device *device,
-  gx_color_value red, gx_color_value green, gx_color_value blue)
+  const gx_color_value cv[])
 {
+  gx_color_value red = cv[0]; 
+  gx_color_value green = cv[1]; 
+  gx_color_value blue = cv[2];
   static const gx_color_value half = gx_max_color_value/2;
   gx_color_index value = 0;
   const eprn_Device *dev = (eprn_Device *)device;
@@ -197,8 +200,11 @@
 ******************************************************************************/
 
 gx_color_index eprn_map_rgb_color_for_CMY_or_K(gx_device *device,
-  gx_color_value red, gx_color_value green, gx_color_value blue)
+  const gx_color_value cv[])
 {
+  gx_color_value red = cv[0];
+  gx_color_value green = cv[1];
+  gx_color_value blue = cv[2];
   static const gx_color_value half = gx_max_color_value/2;
   gx_color_index value = (CYAN_BIT | MAGENTA_BIT | YELLOW_BIT);
   const eprn_Device *dev = (eprn_Device *)device;
@@ -240,8 +246,11 @@
 ******************************************************************************/
 
 gx_color_index eprn_map_rgb_color_for_RGB_flex(gx_device *device,
-  gx_color_value red, gx_color_value green, gx_color_value blue)
+  const gx_color_value cv[])
 {
+  gx_color_value red = cv[0]; 
+  gx_color_value green = cv[1]; 
+  gx_color_value blue = cv[2];
   gx_color_index value = 0;
   gx_color_value step;
   unsigned int level;
@@ -284,8 +293,12 @@
 ******************************************************************************/
 
 gx_color_index eprn_map_rgb_color_for_CMY_or_K_flex(gx_device *device,
-  gx_color_value red, gx_color_value green, gx_color_value blue)
+  const gx_color_value cv[])
 {
+  gx_color_value red = cv[0];
+  gx_color_value green = cv[1];
+  gx_color_value blue = cv[2];
+  gx_color_value tmpcv[4];
   const eprn_Device *dev = (eprn_Device *)device;
 
 #ifdef EPRN_TRACE
@@ -298,11 +311,17 @@
   /* Treat pure grey levels differently if we have black. This implies that for
      CMY+K only "true" grey shades will be printed with black ink, all others
      will be mixed from CMY. */
-  if (dev->eprn.colour_model != eprn_DeviceCMY && red == green && green == blue)
-    return eprn_map_cmyk_color_flex(device, 0, 0, 0, gx_max_color_value - red);
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
@@ -315,8 +334,11 @@
 ******************************************************************************/
 
 gx_color_index eprn_map_rgb_color_for_RGB_max(gx_device *device,
-  gx_color_value red, gx_color_value green, gx_color_value blue)
+  const gx_color_value cv[])
 {
+  gx_color_value red = cv[0]; 
+  gx_color_value green = cv[1];
+  gx_color_value blue = cv[2];
   gx_color_index value;
 
 #ifdef EPRN_TRACE
@@ -345,8 +367,12 @@
 ******************************************************************************/
 
 gx_color_index eprn_map_rgb_color_for_CMY_or_K_max(gx_device *device,
-  gx_color_value red, gx_color_value green, gx_color_value blue)
+  const gx_color_value cv[])
 {
+  gx_color_value red = cv[0];
+  gx_color_value green = cv[1];
+  gx_color_value blue = cv[2];
+  gx_color_value tmpcv[4];
   const eprn_Device *dev = (eprn_Device *)device;
 
 #ifdef EPRN_TRACE
@@ -356,13 +382,18 @@
     red, green, blue);
 #endif
 
-  if (dev->eprn.colour_model == eprn_DeviceGray)
-    return eprn_map_cmyk_color_max(device, 0, 0, 0, gx_max_color_value - red);
-
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
@@ -389,7 +420,7 @@
 ******************************************************************************/
 
 int eprn_map_color_rgb(gx_device *device, gx_color_index color,
-  gx_color_value rgb[3])
+  gx_color_value rgb[])
 {
 #ifdef EPRN_TRACE
   if_debug1(EPRN_TRACE_CHAR,
@@ -415,9 +446,12 @@
 ******************************************************************************/
 
 gx_color_index eprn_map_cmyk_color(gx_device *device,
-  gx_color_value cyan, gx_color_value magenta, gx_color_value yellow,
-  gx_color_value black)
+  const gx_color_value cv[])
 {
+  gx_color_value cyan = cv[0];
+  gx_color_value magenta = cv[1];
+  gx_color_value yellow = cv[2];
+  gx_color_value black = cv[3];
   gx_color_index value = 0;
   static const gx_color_value threshold = gx_max_color_value/2;
 
@@ -449,9 +483,12 @@
 ******************************************************************************/
 
 gx_color_index eprn_map_cmyk_color_flex(gx_device *device,
-  gx_color_value cyan, gx_color_value magenta, gx_color_value yellow,
-  gx_color_value black)
+  const gx_color_value cv[])
 {
+  gx_color_value cyan = cv[0];
+  gx_color_value magenta = cv[1];
+  gx_color_value yellow = cv[2];
+  gx_color_value black = cv[3];
   gx_color_index value = 0;
   gx_color_value step;
   unsigned int level;
@@ -530,9 +567,12 @@
 ******************************************************************************/
 
 gx_color_index eprn_map_cmyk_color_max(gx_device *device,
-  gx_color_value cyan, gx_color_value magenta, gx_color_value yellow,
-  gx_color_value black)
+  const gx_color_value cv[])
 {
+  gx_color_value cyan = cv[0];
+  gx_color_value magenta = cv[1];
+  gx_color_value yellow = cv[2];
+  gx_color_value black = cv[3];
   gx_color_index value;
 
 #ifdef EPRN_TRACE
