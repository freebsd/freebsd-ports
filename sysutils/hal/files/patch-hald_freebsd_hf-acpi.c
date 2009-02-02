--- hald/freebsd/hf-acpi.c.orig	2008-05-07 19:23:59.000000000 -0400
+++ hald/freebsd/hf-acpi.c	2009-01-30 15:53:14.000000000 -0500
@@ -105,6 +105,9 @@ hf_acpi_poll_batt (HalDevice *device)
   gboolean ispresent;
   union acpi_battery_ioctl_arg battif, battst, battinfo;
 
+  if (! hf_has_sysctl("hw.acpi.battery"))
+    return;
+
   battif.unit = battst.unit = battinfo.unit =
     hal_device_property_get_int(device, "freebsd.unit");
 
@@ -504,6 +507,8 @@ hf_acpi_laptop_panel_new (HalDevice *par
 
   g_return_val_if_fail(HAL_IS_DEVICE(parent), NULL);
 
+  if (! hf_has_sysctl("hw.acpi.%s", access))
+    return NULL;
   device = hf_device_new(parent);
 
   hf_device_property_set_string_printf(device, "info.product", "Laptop Panel (%s)", name);
@@ -597,7 +602,8 @@ hf_acpi_probe (void)
 						      laptop_panel_types[i].max_sysctl,
 						      laptop_panel_types[i].access,
 						      laptop_panel_types[i].name);
-	      hf_device_preprobe_and_add(panel_device);
+	      if (panel_device)
+		hf_device_preprobe_and_add(panel_device);
 	    }
 	}
     }
