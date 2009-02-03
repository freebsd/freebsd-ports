--- hald/freebsd/hf-acpi.c.orig	2008-05-07 19:23:59.000000000 -0400
+++ hald/freebsd/hf-acpi.c	2009-02-02 20:32:05.000000000 -0500
@@ -105,6 +105,9 @@
   gboolean ispresent;
   union acpi_battery_ioctl_arg battif, battst, battinfo;
 
+  if (! hf_has_sysctl("hw.acpi.battery.units"))
+    return;
+
   battif.unit = battst.unit = battinfo.unit =
     hal_device_property_get_int(device, "freebsd.unit");
 
@@ -500,10 +503,17 @@
                           const char *max_sysctl, const char *access,
                           const char *name)
 {
+  char *brightness;
   HalDevice *device;
 
   g_return_val_if_fail(HAL_IS_DEVICE(parent), NULL);
 
+  if (! strcmp(access, "sony"))
+    brightness = "brightness";
+  else
+    brightness = "lcd_brightness";
+  if (! hf_has_sysctl("hw.acpi.%s.%s", access, brightness))
+    return NULL;
   device = hf_device_new(parent);
 
   hf_device_property_set_string_printf(device, "info.product", "Laptop Panel (%s)", name);
@@ -597,7 +607,8 @@
 						      laptop_panel_types[i].max_sysctl,
 						      laptop_panel_types[i].access,
 						      laptop_panel_types[i].name);
-	      hf_device_preprobe_and_add(panel_device);
+	      if (panel_device)
+		hf_device_preprobe_and_add(panel_device);
 	    }
 	}
     }
