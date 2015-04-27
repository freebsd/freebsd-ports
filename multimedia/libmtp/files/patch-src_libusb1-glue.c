Reset libusb_context for successive init_usb() calls instead of error

https://github.com/phatina/simple-mtpfs/issues/37

--- src/libusb1-glue.c.orig	2015-04-09 21:10:06 UTC
+++ src/libusb1-glue.c
@@ -142,7 +142,7 @@ static LIBMTP_error_number_t init_usb()
    * We use the same level debug between MTP and USB.
    */
   if (libusb1_initialized)
-     return LIBMTP_ERROR_NONE;
+    libusb_exit(NULL);
 
   if (libusb_init(NULL) < 0) {
     LIBMTP_ERROR("Libusb1 init failed\n");
