--- libpconn/PConnection_usb.c.orig	Thu Jul  1 01:51:27 2004
+++ libpconn/PConnection_usb.c	Thu Jul  1 01:56:57 2004
@@ -41,6 +41,10 @@
 #  include <libintl.h>		/* For i18n */
 #endif	/* HAVE_LIBINTL_H */
 
+#if !HAVE_USLEEP
+int usleep(unsigned int usec);	/* defined in PConnection_serial.c */
+#endif
+
 #include "pconn/PConnection.h"
 #include "palm.h"
 #include "pconn/palm_errno.h"
@@ -439,7 +443,7 @@
 	 *  you'll get an ENXIO until the device has been inserted
 	 *  on the USB bus.
 	 */
-	for (i = 0; i < 30; i++) {
+	for (i = 0; i < 30 * (1000000 / 50000); i++) {
 		if ((usb_ep0 = open(device, O_RDWR | O_BINARY)) >= 0) 
 				/* The O_BINARY flag is rather bogus, since
 				 * the only relevant platform that uses it
@@ -465,7 +469,7 @@
 			 */
 			break;
 		}
-		sleep(1);
+		usleep(50000);
 	}
 
 	/*
@@ -711,7 +715,7 @@
 			    ((flags & PCONNFL_TRANSIENT) != 0))
 			{
 				/* Ignore this error and try again */
-				sleep(1);
+				usleep(10000);
 				continue;
 			}
 
