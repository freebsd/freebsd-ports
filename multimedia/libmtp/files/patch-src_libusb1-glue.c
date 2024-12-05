Reset libusb_context for successive init_usb() calls instead of error

https://github.com/phatina/simple-mtpfs/issues/37

--- src/libusb1-glue.c.orig	2023-12-21 08:27:04 UTC
+++ src/libusb1-glue.c
@@ -153,7 +153,7 @@ static LIBMTP_error_number_t init_usb()
    * We use the same level debug between MTP and USB.
    */
   if (libusb1_initialized)
-     return LIBMTP_ERROR_NONE;
+    libusb_exit(NULL);
 
   if (libusb_init(&libmtp_libusb_context) < 0) {
     LIBMTP_ERROR("Libusb1 init failed\n");
@@ -163,8 +163,8 @@ static LIBMTP_error_number_t init_usb()
   libusb1_initialized = 1;
 
   if ((LIBMTP_debug & LIBMTP_DEBUG_USB) != 0)
-    /*libusb_set_debug(libmtp_libusb_context,9);*/
-    libusb_set_option(libmtp_libusb_context, LIBUSB_OPTION_LOG_LEVEL,  LIBUSB_LOG_LEVEL_DEBUG ); /* highest level */
+    libusb_set_debug(libmtp_libusb_context,9);
+    // libusb_set_option(libmtp_libusb_context, LIBUSB_OPTION_LOG_LEVEL,  LIBUSB_LOG_LEVEL_DEBUG ); /* highest level */
   return LIBMTP_ERROR_NONE;
 }
 
