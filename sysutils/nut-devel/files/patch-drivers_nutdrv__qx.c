--- drivers/nutdrv_qx.c.orig	2016-03-08 12:01:11 UTC
+++ drivers/nutdrv_qx.c
@@ -561,9 +561,9 @@ static int	phoenix_command(const char *cmd, char *buf,
 		 * In order to read correct replies we need to flush the output buffers of the converter until we get no more data (ie, it times out). */
 		switch (ret)
 		{
-		case -EPIPE:		/* Broken pipe */
+		case LIBUSB_ERROR_PIPE:		/* Broken pipe */
 			usb_clear_halt(udev, 0x81);
-		case -ETIMEDOUT:	/* Connection timed out */
+		case LIBUSB_ERROR_TIMEOUT:	/* Connection timed out */
 			break;
 		}
 
@@ -635,7 +635,7 @@ static int	ippon_command(const char *cmd, char *buf, s
 		ret = usb_control_msg(udev, USB_ENDPOINT_OUT + USB_TYPE_CLASS + USB_RECIP_INTERFACE, 0x09, 0x2, 0, &tmp[i], 8, 1000);
 
 		if (ret <= 0) {
-			upsdebugx(3, "send: %s (%d)", (ret != -ETIMEDOUT) ? usb_strerror() : "Connection timed out", ret);
+			upsdebugx(3, "send: %s (%d)", (ret != LIBUSB_ERROR_TIMEOUT) ? usb_strerror() : "Connection timed out", ret);
 			return ret;
 		}
 
@@ -648,7 +648,7 @@ static int	ippon_command(const char *cmd, char *buf, s
 
 	/* Any errors here mean that we are unable to read a reply (which will happen after successfully writing a command to the UPS) */
 	if (ret <= 0) {
-		upsdebugx(3, "read: %s (%d)", (ret != -ETIMEDOUT) ? usb_strerror() : "Connection timed out", ret);
+		upsdebugx(3, "read: %s (%d)", (ret != LIBUSB_ERROR_TIMEOUT) ? usb_strerror() : "Connection timed out", ret);
 		return ret;
 	}
 
@@ -2124,38 +2124,28 @@ static int	qx_command(const char *cmd, char *buf, size
 
 		switch (ret)
 		{
-		case -EBUSY:		/* Device or resource busy */
+		case LIBUSB_ERROR_BUSY:		/* Device or resource busy */
 			fatal_with_errno(EXIT_FAILURE, "Got disconnected by another driver");
 
-		case -EPERM:		/* Operation not permitted */
-			fatal_with_errno(EXIT_FAILURE, "Permissions problem");
-
-		case -EPIPE:		/* Broken pipe */
+		case LIBUSB_ERROR_PIPE:		/* Broken pipe */
 			if (usb_clear_halt(udev, 0x81) == 0) {
 				upsdebugx(1, "Stall condition cleared");
 				break;
 			}
-	#ifdef ETIME
-		case -ETIME:		/* Timer expired */
-	#endif	/* ETIME */
 			if (usb_reset(udev) == 0) {
 				upsdebugx(1, "Device reset handled");
 			}
-		case -ENODEV:		/* No such device */
-		case -EACCES:		/* Permission denied */
-		case -EIO:		/* I/O error */
-		case -ENXIO:		/* No such device or address */
-		case -ENOENT:		/* No such file or directory */
+		case LIBUSB_ERROR_NO_DEVICE: /* No such device */
+		case LIBUSB_ERROR_ACCESS:    /* Permission denied */
+		case LIBUSB_ERROR_IO:        /* I/O error */
+		case LIBUSB_ERROR_NOT_FOUND: /* No such file or directory */
 			/* Uh oh, got to reconnect! */
 			usb->close(udev);
 			udev = NULL;
 			break;
 
-		case -ETIMEDOUT:	/* Connection timed out */
-		case -EOVERFLOW:	/* Value too large for defined data type */
-#ifdef EPROTO
-		case -EPROTO:		/* Protocol error */
-#endif
+		case LIBUSB_ERROR_TIMEOUT:  /* Connection timed out */
+		case LIBUSB_ERROR_OVERFLOW: /* Value too large for defined data type */
 		default:
 			break;
 		}
