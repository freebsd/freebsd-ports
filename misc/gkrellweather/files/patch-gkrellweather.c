--- gkrellweather.c.orig	Sun May 20 03:04:50 2001
+++ gkrellweather.c	Mon Aug 20 05:21:41 2001
@@ -243,7 +243,7 @@
             decal_unit2->w;
         decal_temperature->x = (gkrellm_chart_width() - w + 1) / 2 + 1;
         decal_unit1->x = decal_temperature->x + decal_temperature->w - 1;
-        decal_humidity->x = decal_unit1->x + decal_unit1->w + 1;
+        decal_humidity->x = decal_unit1->x + decal_unit1->w;
         decal_unit2->x = decal_humidity->x + decal_humidity->w - 1;
         break;
     }
@@ -500,7 +500,7 @@
     ext_unit1.ts = *gkrellm_meter_textstyle(cal_style_id);
     string_extents("C", &ext_unit1);
     ext_humidity.ts = *gkrellm_meter_alt_textstyle(clock_style_id);
-    string_extents("88", &ext_humidity);
+    string_extents("888", &ext_humidity);
     ext_unit2.ts = *gkrellm_meter_textstyle(cal_style_id);
     string_extents("%", &ext_unit2);
     ext_dew_point.ts = *gkrellm_meter_alt_textstyle(clock_style_id);
@@ -522,7 +522,7 @@
             &ext_temperature.ts, style, 0, 3, ext_temperature.width + 2);
     decal_unit1 = gkrellm_create_decal_text(panel, "C", &ext_unit1.ts,
             style, 0, 3, ext_unit1.width + 2);
-    decal_humidity = gkrellm_create_decal_text(panel, "88", &ext_humidity.ts,
+    decal_humidity = gkrellm_create_decal_text(panel, "888", &ext_humidity.ts,
             style, 0, 3, ext_humidity.width + 2);
     decal_unit2 = gkrellm_create_decal_text(panel, "%", &ext_unit2.ts,
             style, 0, 3, ext_unit2.width + 2);
