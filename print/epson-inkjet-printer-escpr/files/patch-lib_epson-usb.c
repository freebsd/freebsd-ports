--- lib/epson-usb.c.orig	2023-02-15 02:57:29 UTC
+++ lib/epson-usb.c
@@ -709,7 +709,7 @@ EPS_ERR_CODE   usbResetPrinter (
 #define EPS_RSREPLY_SIZE	(32)
     EPS_ERR_CODE    Ret;
     EPS_INT32       ComSize = 0;
-    EPS_INT32       retBufSize;                         /* Size of buffer written       */
+    EPS_INT32       retBufSize __unused;                         /* Size of buffer written       */
     EPS_INT32       retryComm;
     EPS_INT32       retryReset;
     EPS_INT32       Size = EPS_RSREPLY_SIZE;
@@ -2325,7 +2325,7 @@ static EPS_ERR_CODE   GetSerialNumber (
 		EPS_RETURN( ret );
 	}
 
-	tmpBuff = (EPS_INT8*)EPS_ALLOC(tmpBuffSize);
+	tmpBuff = (EPS_UINT8*)EPS_ALLOC(tmpBuffSize);
 	if (tmpBuff == NULL) {
 		EPS_RETURN( EPS_ERR_MEMORY_ALLOCATION );
 	}
