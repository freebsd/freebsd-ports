--- lib/epson-usb.c.orig	2017-03-24 04:35:04 UTC
+++ lib/epson-usb.c
@@ -2325,7 +2325,7 @@ static EPS_ERR_CODE   GetSerialNumber (
 		EPS_RETURN( ret );
 	}
 
-	tmpBuff = (EPS_INT8*)EPS_ALLOC(tmpBuffSize);
+	tmpBuff = (EPS_UINT8*)EPS_ALLOC(tmpBuffSize);
 	if (tmpBuff == NULL) {
 		EPS_RETURN( EPS_ERR_MEMORY_ALLOCATION );
 	}
