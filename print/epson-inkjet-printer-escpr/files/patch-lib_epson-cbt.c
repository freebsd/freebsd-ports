--- lib/epson-cbt.c.orig	2023-02-15 02:57:29 UTC
+++ lib/epson-cbt.c
@@ -651,7 +651,9 @@ static EPS_INT32    commClose (
 
 ){
     EPS_INT32 Ret           = EPCBT_ERR_NONE;
+#ifdef COMM_DBG_ERROR
     EPS_INT32 closePtlState = 0;
+#endif
 
 	EPS_LOG_FUNCIN;
 
@@ -661,7 +663,9 @@ static EPS_INT32    commClose (
     {
         Ret = EPCBT_Close(fd);    /* Channel close & cbt exit */
 
+#ifdef COMM_DBG_ERROR
         closePtlState = epsUsbFnc.closePortal(fd);
+#endif
 
         ioOpenState = EPS_IO_NOT_OPEN;        /* Open flag Off */
     }
