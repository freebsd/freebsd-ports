--- drivers/tripplite_usb.c.orig	2015-12-29 12:08:34 UTC
+++ drivers/tripplite_usb.c
@@ -499,7 +499,7 @@ void usb_comm_fail(int res, const char *msg)
 	static int try = 0;
 
 	switch(res) {
-		case -EBUSY:
+		case LIBUSB_ERROR_BUSY:
 			upslogx(LOG_WARNING, "%s: Device claimed by another process", msg);
 			fatalx(EXIT_FAILURE, "Terminating: EBUSY");
 			break;
@@ -907,7 +907,7 @@ void upsdrv_initinfo(void)
 	if(tl_model != TRIPP_LITE_SMARTPRO ) {
 		ret = send_cmd(w_msg, sizeof(w_msg), w_value, sizeof(w_value)-1);
 		if(ret <= 0) {
-			if(ret == -EPIPE) {
+			if(ret == LIBUSB_ERROR_PIPE) {
 				fatalx(EXIT_FAILURE, "Could not reset watchdog. Please check and"
 						"see if usbhid-ups(8) works with this UPS.");
 			} else {
