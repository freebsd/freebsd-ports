--- hald/freebsd/hf-usb.h.orig	2009-02-17 18:56:56.000000000 -0500
+++ hald/freebsd/hf-usb.h	2009-02-17 18:57:21.000000000 -0500
@@ -34,4 +34,7 @@
 extern HFHandler hf_usb_handler;
 extern HFDevdHandler hf_usb_devd_handler;
 
+void hf_usb_device_compute_udi(HalDevice *device);
+void hf_usb_add_webcam_properties(HalDevice *device);
+
 #endif /* _HF_USB_H */
