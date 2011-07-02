--- hald/freebsd/probing/probe-usb2-device.c.orig	2011-06-30 13:46:55.000000000 +0200
+++ hald/freebsd/probing/probe-usb2-device.c	2011-06-30 13:49:19.000000000 +0200
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
