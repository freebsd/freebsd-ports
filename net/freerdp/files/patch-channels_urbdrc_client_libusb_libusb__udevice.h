--- channels/urbdrc/client/libusb/libusb_udevice.h.orig	2020-05-20 14:45:43 UTC
+++ channels/urbdrc/client/libusb/libusb_udevice.h
@@ -75,4 +75,8 @@ IUDEVICE* udev_new_by_addr(URBDRC_PLUGIN* urbdrc, libu
                            BYTE dev_number);
 const char* usb_interface_class_to_string(uint8_t class);
 
+#ifndef LIBUSB_CLASS_PHYSICAL
+#define LIBUSB_CLASS_PHYSICAL 5
+#endif
+
 #endif /* FREERDP_CHANNEL_URBDRC_CLIENT_LIBUSB_UDEVICE_H */
