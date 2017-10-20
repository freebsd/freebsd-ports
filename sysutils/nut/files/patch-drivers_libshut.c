--- drivers/libshut.c.orig	2015-12-29 12:08:34 UTC
+++ drivers/libshut.c
@@ -809,10 +809,10 @@ int shut_get_string_simple(int upsfd, int index,
 		return ret;
 
 	if (tbuf[1] != USB_DT_STRING)
-		return -EIO;
+		return LIBUSB_ERROR_IO;
 
 	if (tbuf[0] > ret)
-		return -EFBIG;
+		return LIBUSB_ERROR_OVERFLOW;
 
 	/* skip the UTF8 zero'ed high bytes */
 	for (di = 0, si = 2; si < tbuf[0]; si += 2)
