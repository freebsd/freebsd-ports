--- uhidd/uhidd.c~
+++ uhidd/uhidd.c
@@ -313,7 +313,6 @@
 static int
 open_device(const char *dev, struct libusb20_device *pdev)
 {
-	struct LIBUSB20_DEVICE_DESC_DECODED *ddesc;
 	struct libusb20_config *config;
 	struct libusb20_interface *iface;
 	int cndx, e, i;
@@ -334,8 +333,6 @@ open_device(const char *dev, struct libu
 		return (-1);
 	}
 
-	ddesc = libusb20_dev_get_device_desc(pdev);
-
 	/*
 	 * Iterate each interface.
 	 */
