--- tools/usbredirect.c.orig	2026-04-03 09:26:53 UTC
+++ tools/usbredirect.c
@@ -469,7 +469,7 @@ main(int argc, char *argv[])
 #ifdef G_OS_WIN32
     /* WinUSB is the default by backwards compatibility so this is needed to
      * switch to USBDk backend. */
-    libusb_set_option(NULL, LIBUSB_OPTION_USE_USBDK); 
+    libusb_set_option(NULL, LIBUSB_OPTION_USE_USBDK);
 #endif
 
 #ifdef G_OS_UNIX
@@ -528,7 +528,11 @@ main(int argc, char *argv[])
     /* Only allow libusb logging if log verbosity is uredirparser_debug_data
      * (or higher), otherwise we disable it here while keeping usbredir's logs enable. */
     if  (self->verbosity < usbredirparser_debug_data)  {
+#if LIBUSB_API_VERSION >= 0x01000106
         int ret = libusb_set_option(NULL, LIBUSB_OPTION_LOG_LEVEL, LIBUSB_LOG_LEVEL_NONE);
+#else
+        int ret = (libusb_set_debug(NULL, LIBUSB_LOG_LEVEL_NONE), 0);
+#endif
         if (ret != LIBUSB_SUCCESS) {
             g_warning("error disabling libusb log level: %s", libusb_error_name(ret));
             goto end;
