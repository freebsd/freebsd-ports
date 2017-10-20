--- drivers/blazer_usb.c.orig	2015-12-29 12:08:34 UTC
+++ drivers/blazer_usb.c
@@ -118,9 +118,9 @@ static int phoenix_command(const char *cmd, char *buf,
 		 */
 		switch (ret)
 		{
-		case -EPIPE:		/* Broken pipe */
+		case LIBUSB_ERROR_PIPE:		/* Broken pipe */
 			usb_clear_halt(udev, 0x81);
-		case -ETIMEDOUT:	/* Connection timed out */
+		case LIBUSB_ERROR_TIMEOUT:	/* Connection timed out */
 			break;
 		}
 
@@ -188,7 +188,7 @@ static int ippon_command(const char *cmd, char *buf, s
 			0x09, 0x2, 0, &tmp[i], 8, 1000);
 
 		if (ret <= 0) {
-			upsdebugx(3, "send: %s", (ret != -ETIMEDOUT) ? usb_strerror() : "Connection timed out");
+			upsdebugx(3, "send: %s", (ret != LIBUSB_ERROR_TIMEOUT) ? usb_strerror() : "Connection timed out");
 			return ret;
 		}
 	}
@@ -203,7 +203,7 @@ static int ippon_command(const char *cmd, char *buf, s
 	 * will happen after successfully writing a command to the UPS)
 	 */
 	if (ret <= 0) {
-		upsdebugx(3, "read: %s", (ret != -ETIMEDOUT) ? usb_strerror() : "Connection timed out");
+		upsdebugx(3, "read: %s", (ret != LIBUSB_ERROR_TIMEOUT) ? usb_strerror() : "Connection timed out");
 		return ret;
 	}
 
@@ -423,38 +423,28 @@ int blazer_command(const char *cmd, char *buf, size_t 
 
 	switch (ret)
 	{
-	case -EBUSY:		/* Device or resource busy */
+	case LIBUSB_ERROR_BUSY:		/* Device or resource busy */
 		fatal_with_errno(EXIT_FAILURE, "Got disconnected by another driver");
 
-	case -EPERM:		/* Operation not permitted */
-		fatal_with_errno(EXIT_FAILURE, "Permissions problem");
-
-	case -EPIPE:		/* Broken pipe */
+	case LIBUSB_ERROR_PIPE:		/* Broken pipe */
 		if (usb_clear_halt(udev, 0x81) == 0) {
 			upsdebugx(1, "Stall condition cleared");
 			break;
 		}
-#ifdef ETIME
-	case -ETIME:		/* Timer expired */
-#endif
 		if (usb_reset(udev) == 0) {
 			upsdebugx(1, "Device reset handled");
 		}
-	case -ENODEV:		/* No such device */
-	case -EACCES:		/* Permission denied */
-	case -EIO:		/* I/O error */
-	case -ENXIO:		/* No such device or address */
-	case -ENOENT:		/* No such file or directory */
+	case LIBUSB_ERROR_NO_DEVICE: /* No such device */
+	case LIBUSB_ERROR_ACCESS:    /* Permission denied */
+	case LIBUSB_ERROR_IO:        /* I/O error */
+	case LIBUSB_ERROR_NOT_FOUND: /* No such file or directory */
 		/* Uh oh, got to reconnect! */
 		usb->close(udev);
 		udev = NULL;
 		break;
 
-	case -ETIMEDOUT:	/* Connection timed out */
-	case -EOVERFLOW:	/* Value too large for defined data type */
-#ifdef EPROTO
-	case -EPROTO:		/* Protocol error */
-#endif
+	case LIBUSB_ERROR_TIMEOUT:  /* Connection timed out */
+	case LIBUSB_ERROR_OVERFLOW: /* Value too large for defined data type */
 	default:
 		break;
 	}
