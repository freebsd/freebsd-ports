--- src/ifd/ifd-wbeiuu.c.orig	Sat Oct  7 09:55:18 2006
+++ src/ifd/ifd-wbeiuu.c	Sat Oct  7 09:57:25 2006
@@ -454,6 +454,7 @@
 {
 	int status;
 	unsigned char buf[256];
+	unsigned char len;
 	ifd_device_t *dev;
 
 	ifd_debug(1, "%s:%d wbeiuu_card_reset()", __FILE__, __LINE__);
@@ -504,7 +505,6 @@
 		return -1;
 	}
 	//unsigned char len[1] = { 0x00 };
-	unsigned char len;
 	ifd_debug(1, "%s:%d How many bytes waiting at the FIFO?", __FILE__,
 		  __LINE__, status);
 	status = ifd_sysdep_usb_bulk(dev, 0x82, &len, 1, USB_TIMEOUT);
