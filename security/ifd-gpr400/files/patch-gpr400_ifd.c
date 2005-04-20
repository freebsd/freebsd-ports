--- gpr400_ifd.c.orig	Wed Aug 22 04:21:43 2001
+++ gpr400_ifd.c	Mon Apr 11 21:09:23 2005
@@ -77,7 +77,7 @@
 	printf("IFDHCreateChannel:\n");
 #endif
     if(gpr_fd < 0){
-        gpr_fd= open("/dev/gpr400", O_RDWR);
+        gpr_fd= open(GPRDEVNAME, O_RDWR);
         if(gpr_fd < 0){
             return IFD_COMMUNICATION_ERROR;
         }
@@ -597,16 +597,6 @@
      RxLength should be zero on error.
  *
  **/
-RESPONSECODE IFDHControl ( DWORD Lun, PUCHAR TxBuffer, 
-			 DWORD TxLength, PUCHAR RxBuffer, 
-			 PDWORD RxLength ) 
-{
-#ifdef PCSC_DEBUG
-	printf("IFDHControl:\n");
-#endif
-    return IFD_NOT_SUPPORTED;
-
-}/* IFDHControl */
 
 /**
  * check if there is a smartcard in the reader
