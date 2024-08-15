--- mtp/backend/libusb/usb/Context.cpp.orig	2024-07-16 19:25:15 UTC
+++ mtp/backend/libusb/usb/Context.cpp
@@ -27,7 +27,7 @@ namespace mtp { namespace usb
 	Context::Context(int debugLevel)
 	{
 		USB_CALL(libusb_init(&_ctx));
-		libusb_set_debug(_ctx, debugLevel);
+		//libusb_set_debug(_ctx, debugLevel);
 		libusb_device **devs;
 		int count = libusb_get_device_list(_ctx, &devs);
 		if (count < 0)
