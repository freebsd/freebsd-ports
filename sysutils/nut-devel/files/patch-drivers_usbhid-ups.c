--- drivers/usbhid-ups.c.orig	2015-12-29 12:08:34 UTC
+++ drivers/usbhid-ups.c
@@ -30,6 +30,7 @@
 #define DRIVER_VERSION		"0.41"
 
 #include "main.h"
+#include "libusb.h"
 #include "libhid.h"
 #include "usbhid-ups.h"
 #include "hidparser.h"
@@ -790,22 +790,14 @@ void upsdrv_updateinfo(void)
 	/* Get HID notifications on Interrupt pipe first */
 	if (use_interrupt_pipe == TRUE) {
 		evtCount = HIDGetEvents(udev, event, MAX_EVENT_NUM);
-		switch (evtCount)
-		{
-		case -EBUSY:		/* Device or resource busy */
-			upslog_with_errno(LOG_CRIT, "Got disconnected by another driver");
-		case -EPERM:		/* Operation not permitted */
-		case -ENODEV:		/* No such device */
-		case -EACCES:		/* Permission denied */
-		case -EIO:		/* I/O error */
-		case -ENXIO:		/* No such device or address */
-		case -ENOENT:		/* No such file or directory */
+		if (evtCount < 0) {
+			if (evtCount == LIBUSB_ERROR_BUSY) {
+				upslog_with_errno(LOG_CRIT, "Got disconnected by another driver");
+			}
 			/* Uh oh, got to reconnect! */
 			hd = NULL;
-			return;
-		default:
+		} else {
 			upsdebugx(1, "Got %i HID objects...", (evtCount >= 0) ? evtCount : 0);
-			break;
 		}
 	} else {
 		evtCount = 0;
@@ -1280,14 +1272,12 @@ static bool_t hid_ups_walk(walkmode_t mode)
 
 		switch (retcode)
 		{
-		case -EBUSY:		/* Device or resource busy */
+		case LIBUSB_ERROR_BUSY:		/* Device or resource busy */
 			upslog_with_errno(LOG_CRIT, "Got disconnected by another driver");
-		case -EPERM:		/* Operation not permitted */
-		case -ENODEV:		/* No such device */
-		case -EACCES:		/* Permission denied */
-		case -EIO:		/* I/O error */
-		case -ENXIO:		/* No such device or address */
-		case -ENOENT:		/* No such file or directory */
+		case LIBUSB_ERROR_NO_DEVICE:		/* No such device */
+		case LIBUSB_ERROR_ACCESS:		/* Permission denied */
+		case LIBUSB_ERROR_IO:			/* I/O error */
+		case LIBUSB_ERROR_NOT_FOUND:		/* No such file or directory */
 			/* Uh oh, got to reconnect! */
 			hd = NULL;
 			return FALSE;
@@ -1298,12 +1288,9 @@ static bool_t hid_ups_walk(walkmode_t mode)
 		case 0:
 			continue;
 
-		case -ETIMEDOUT:	/* Connection timed out */
-		case -EOVERFLOW:	/* Value too large for defined data type */
-#ifdef EPROTO
-		case -EPROTO:		/* Protocol error */
-#endif
-		case -EPIPE:		/* Broken pipe */
+		case LIBUSB_ERROR_TIMEOUT:	/* Connection timed out */
+		case LIBUSB_ERROR_OVERFLOW:	/* Value too large for defined data type */
+		case LIBUSB_ERROR_PIPE:		/* Broken pipe */
 		default:
 			/* Don't know what happened, try again later... */
 			continue;
