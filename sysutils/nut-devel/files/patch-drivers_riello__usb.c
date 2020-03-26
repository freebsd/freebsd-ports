--- drivers/riello_usb.c.orig	2015-12-29 12:08:34 UTC
+++ drivers/riello_usb.c
@@ -346,42 +346,28 @@ int riello_command(uint8_t *cmd, uint8_t *buf, uint16_
 
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
-		upsdebugx (3, "riello_command err: Resource temporarily unavailable");
-
-
-	case -EOVERFLOW:	/* Value too large for defined data type */
-#ifdef EPROTO
-	case -EPROTO:		/* Protocol error */
-#endif
-		break;
+	case LIBUSB_ERROR_TIMEOUT:  /* Connection timed out */
+	case LIBUSB_ERROR_OVERFLOW: /* Value too large for defined data type */
 	default:
 		break;
 	}
