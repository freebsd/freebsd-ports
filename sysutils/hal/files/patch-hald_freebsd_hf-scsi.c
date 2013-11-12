--- ./hald/freebsd/hf-scsi.c.orig	2009-08-24 14:42:29.000000000 +0200
+++ ./hald/freebsd/hf-scsi.c	2013-10-23 13:11:08.979758920 +0200
@@ -223,7 +223,7 @@
 	      hal_device_copy_property(parent, "scsi.lun", device, "storage.lun");
 	      /* do not stop here, in case it's an umass device */
 	    }
-	  else if (! strcmp(bus, "usb"))
+	  else if (hal_device_has_property(parent, "scsi_host.freebsd.driver") && ! strcmp(hal_device_property_get_string(parent, "scsi_host.freebsd.driver"), "umass"))
 	    {
 	      hal_device_property_set_string(device, "storage.bus", "usb");
 	      hal_device_property_set_string(device, "storage.originating_device", hal_device_get_udi(parent));
@@ -508,6 +508,16 @@
 	      if (! parent || ! hal_device_property_get_bool(parent, "info.ignore"))
 		{
 		  device = hf_scsi_bus_device_new(parent, match);
+		  /*
+		   * Due to synchronization problems, the SCSI bus could be
+		   * created before the USB interface. Mark it as a USB mass
+		   * storage device to ensure it is detected as such.
+		   */
+		  if (! strcmp(match->dev_name, "umass-sim"))
+		    {
+		      hal_device_property_set_string(device, "scsi_host.freebsd.driver", "umass");
+		      hal_device_property_set_int(device, "scsi_host.freebsd.unit", match->unit_number);
+		    }
 		  hf_device_preprobe_and_add(device);
 		}
 	    }
