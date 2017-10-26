--- drivers/libusb.c.orig	2015-12-29 12:08:34 UTC
+++ drivers/libusb.c
@@ -428,26 +428,21 @@ static int libusb_strerror(const int ret, const char *
 
 	switch(ret)
 	{
-	case -EBUSY:	/* Device or resource busy */
-	case -EPERM:	/* Operation not permitted */
-	case -ENODEV:	/* No such device */
-	case -EACCES:	/* Permission denied */
-	case -EIO:	/* I/O error */
-	case -ENXIO:	/* No such device or address */
-	case -ENOENT:	/* No such file or directory */
-	case -EPIPE:	/* Broken pipe */
-	case -ENOSYS:	/* Function not implemented */
+	case LIBUSB_ERROR_BUSY:			/* Device or resource busy */
+	case LIBUSB_ERROR_NO_DEVICE:		/* No such device */
+	case LIBUSB_ERROR_ACCESS:		/* Permission denied */
+	case LIBUSB_ERROR_IO:			/* I/O error */
+	case LIBUSB_ERROR_NOT_FOUND:		/* No such file or directory */
+	case LIBUSB_ERROR_PIPE:			/* Broken pipe */
+	case LIBUSB_ERROR_NOT_SUPPORTED:	/* Function not implemented */
 		upslogx(LOG_DEBUG, "%s: %s", desc, usb_strerror());
 		return ret;
 
-	case -ETIMEDOUT:	/* Connection timed out */
+	case LIBUSB_ERROR_TIMEOUT:		/* Connection timed out */
 		upsdebugx(2, "%s: Connection timed out", desc);
 		return 0;
 
-	case -EOVERFLOW:	/* Value too large for defined data type */
-#ifdef EPROTO
-	case -EPROTO:	/* Protocol error */
-#endif
+	case LIBUSB_ERROR_OVERFLOW:		/* Value too large for defined data type */
 		upsdebugx(2, "%s: %s", desc, usb_strerror());
 		return 0;
 
@@ -478,7 +473,7 @@ static int libusb_get_report(usb_dev_handle *udev, int
 		0, raw_buf, ReportSize, USB_TIMEOUT);
 
 	/* Ignore "protocol stall" (for unsupported request) on control endpoint */
-	if (ret == -EPIPE) {
+	if (ret == LIBUSB_ERROR_PIPE) {
 		return 0;
 	}
 
@@ -500,7 +495,7 @@ static int libusb_set_report(usb_dev_handle *udev, int
 		0, raw_buf, ReportSize, USB_TIMEOUT);
 
 	/* Ignore "protocol stall" (for unsupported request) on control endpoint */
-	if (ret == -EPIPE) {
+	if (ret == LIBUSB_ERROR_PIPE) {
 		return 0;
 	}
 
@@ -532,7 +527,7 @@ static int libusb_get_interrupt(usb_dev_handle *udev, 
 	ret = usb_interrupt_read(udev, 0x81, (char *)buf, bufsize, timeout);
 
 	/* Clear stall condition */
-	if (ret == -EPIPE) {
+	if (ret == LIBUSB_ERROR_PIPE) {
 		ret = usb_clear_halt(udev, 0x81);
 	}
 
