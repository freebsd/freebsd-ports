--- hald/freebsd/probing/probe-usb2-device.c.orig	2009-08-24 08:42:29.000000000 -0400
+++ hald/freebsd/probing/probe-usb2-device.c	2012-03-31 15:20:14.000000000 -0400
@@ -100,6 +100,7 @@ main(int argc, char **argv)
       if (pcfg == NULL || libusb20_dev_get_info(pdev, &di))
         {
           free(pcfg);
+	  libusb20_dev_close(pdev);
 	  continue;
 	}
 
@@ -148,15 +149,16 @@ main(int argc, char **argv)
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
@@ -169,6 +171,9 @@ main(int argc, char **argv)
           case UD_USB_2_0:
             version = 2.0;
 	    break;
+	  case 0x0250:
+	    version = 2.5;
+	    break;
 	  case UD_USB_3_0:
 	    version = 3.0;
 	    break;
@@ -184,7 +189,7 @@ main(int argc, char **argv)
       libhal_device_set_property_int(hfp_ctx, hfp_udi,
         "usb_device.vendor_id", di.udi_vendorNo, &hfp_error);
       libhal_device_set_property_int(hfp_ctx, hfp_udi,
-        "usb_device.device_revision_bcd", ddesc->bcdUSB, &hfp_error);
+        "usb_device.device_revision_bcd", ddesc->bcdDevice, &hfp_error);
       libhal_device_set_property_string(hfp_ctx, hfp_udi,
         "usb_device.serial", di.udi_serial, &hfp_error);
       libhal_device_set_property_string(hfp_ctx, hfp_udi,
