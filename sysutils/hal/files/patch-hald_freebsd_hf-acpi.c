--- hald/freebsd/hf-acpi.c.orig	2008-05-07 19:23:59.000000000 -0400
+++ hald/freebsd/hf-acpi.c	2009-02-04 11:32:27.000000000 -0500
@@ -54,6 +54,7 @@
 static const struct laptop_panel_type {
   char *access;
   char *name;
+  char *get_sysctl;
   char *max_sysctl;
   int max_levels;
 #define HF_ACPI_IBM_MAX_LEVELS		8
@@ -64,17 +65,29 @@
 #define HF_ACPI_FUJITSU_MAX_LEVELS	8
   /* NOTE: Each new type must also be added to hf-devtree.c */
 } laptop_panel_types[] = {
-  { "ibm",		"IBM",		NULL,
+  { "ibm",		"IBM",
+    "dev.acpi_ibm.0.lcd_brightness",
+    NULL,
     HF_ACPI_IBM_MAX_LEVELS },
-  { "toshiba",		"Toshiba",	NULL,
+  { "toshiba",		"Toshiba",
+    "hw.acpi.toshiba.lcd_brightness",
+    NULL,
     HF_ACPI_TOSHIBA_MAX_LEVELS },
-  { "sony",		"Sony",		NULL,
+  { "sony",		"Sony",
+    "dev.acpi_sony.0.brightness",
+    NULL,
     HF_ACPI_SONY_MAX_LEVELS },
-  { "panasonic",	"Panasonic",	"hw.acpi.panasonic.lcd_brightness_max",
+  { "panasonic",	"Panasonic",
+    "hw.acpi.panasonic.lcd_brightness",
+    "hw.acpi.panasonic.lcd_brightness_max",
     HF_ACPI_PANASONIC_MAX_LEVELS },
-  { "asus",		"Asus",		NULL,
+  { "asus",		"Asus",
+    "hw.acpi.asus.lcd_brightness",
+    NULL,
     HF_ACPI_ASUS_MAX_LEVELS },
-  { "fujitsu",		"Fujitsu",	NULL,
+  { "fujitsu",		"Fujitsu",
+    "hw.acpi.fujitsu.lcd_brightness",
+    NULL,
     HF_ACPI_FUJITSU_MAX_LEVELS }
 };
 
@@ -105,6 +118,9 @@
   gboolean ispresent;
   union acpi_battery_ioctl_arg battif, battst, battinfo;
 
+  if (! hf_has_sysctl("hw.acpi.battery.units"))
+    return;
+
   battif.unit = battst.unit = battinfo.unit =
     hal_device_property_get_int(device, "freebsd.unit");
 
@@ -497,13 +513,15 @@
 
 static HalDevice *
 hf_acpi_laptop_panel_new (HalDevice *parent, int max_levels,
-                          const char *max_sysctl, const char *access,
-                          const char *name)
+                          const char *get_sysctl, const char *max_sysctl,
+                          const char *access, const char *name)
 {
   HalDevice *device;
 
   g_return_val_if_fail(HAL_IS_DEVICE(parent), NULL);
 
+  if (get_sysctl == NULL || ! hf_has_sysctl(get_sysctl))
+    return NULL;
   device = hf_device_new(parent);
 
   hf_device_property_set_string_printf(device, "info.product", "Laptop Panel (%s)", name);
@@ -593,11 +611,13 @@
               HalDevice *panel_device;
 
 	      panel_device = hf_acpi_laptop_panel_new(parent,
-                                                      laptop_panel_types[i].max_levels,
+						      laptop_panel_types[i].max_levels,
+						      laptop_panel_types[i].get_sysctl,
 						      laptop_panel_types[i].max_sysctl,
 						      laptop_panel_types[i].access,
 						      laptop_panel_types[i].name);
-	      hf_device_preprobe_and_add(panel_device);
+	      if (panel_device)
+		hf_device_preprobe_and_add(panel_device);
 	    }
 	}
     }
