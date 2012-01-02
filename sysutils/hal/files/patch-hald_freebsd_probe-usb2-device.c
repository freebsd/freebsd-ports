--- hald/freebsd/probing/probe-usb2-device.c.orig	2009-08-24 05:42:29.000000000 -0700
+++ hald/freebsd/probing/probe-usb2-device.c	2011-12-30 17:20:52.000000000 -0800
@@ -148,15 +148,16 @@
 	    bcdspeed = 0x01200;
 	    break;
 	  case LIBUSB20_SPEED_HIGH:
+	  case LIBUSB20_SPEED_VARIABLE:
 	    speed = 480.0;
 	    bcdspeed = 0x48000;
 	    break;
 	  case LIBUSB20_SPEED_SUPER:
-	    speed = 4800.0;
-	    bcdspeed = 0x480000;
+	    speed = 5000.0;
+	    bcdspeed = 0x500000;
 	    break;
 	  default:
-	    ;
+	    break;
 	}
 
       libhal_device_set_property_double(hfp_ctx, hfp_udi, "usb_device.speed",
@@ -169,6 +170,9 @@
           case UD_USB_2_0:
             version = 2.0;
 	    break;
+	  case 0x0250:
+	    version = 2.5;
+	    break;
 	  case UD_USB_3_0:
 	    version = 3.0;
 	    break;
@@ -184,7 +188,7 @@
       libhal_device_set_property_int(hfp_ctx, hfp_udi,
         "usb_device.vendor_id", di.udi_vendorNo, &hfp_error);
       libhal_device_set_property_int(hfp_ctx, hfp_udi,
-        "usb_device.device_revision_bcd", ddesc->bcdUSB, &hfp_error);
+        "usb_device.device_revision_bcd", ddesc->bcdDevice, &hfp_error);
       libhal_device_set_property_string(hfp_ctx, hfp_udi,
         "usb_device.serial", di.udi_serial, &hfp_error);
       libhal_device_set_property_string(hfp_ctx, hfp_udi,