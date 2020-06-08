--- channels/urbdrc/client/libusb/libusb_udevman.c.orig	2020-06-08 15:33:51 UTC
+++ channels/urbdrc/client/libusb/libusb_udevman.c
@@ -832,7 +832,7 @@ static DWORD poll_thread(LPVOID lpThreadParameter)
 {
 	libusb_hotplug_callback_handle handle;
 	UDEVMAN* udevman = (UDEVMAN*)lpThreadParameter;
-	BOOL hasHotplug = libusb_has_capability(LIBUSB_CAP_HAS_HOTPLUG);
+	BOOL hasHotplug = TRUE;
 
 	if (hasHotplug)
 	{
