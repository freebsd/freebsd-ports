--- scan/sane/hpaio.c.orig	Tue May 23 15:40:36 2006
+++ scan/sane/hpaio.c	Tue May 23 15:08:07 2006
@@ -1632,10 +1632,11 @@
 extern SANE_Status sane_hpaio_get_parameters( SANE_Handle handle,
                                               SANE_Parameters * pParams )
 {
-    DBG( 0,  "\nhpaio: sane_hpaio_get_parameters()\n" );
-    
     hpaioScanner_t hpaio = ( hpaioScanner_t ) handle;
     char * s = "";
+
+    DBG( 0,  "\nhpaio: sane_hpaio_get_parameters()\n" );
+
     if( !hpaio->hJob )
     {
         *pParams = hpaio->prescanParameters;
@@ -2100,8 +2101,6 @@
 extern SANE_Status sane_hpaio_open( SANE_String_Const devicename,
                                     SANE_Handle * pHandle )
 {
-    DBG( 0,  "\nhpaio:sane_hpaio_open(%s) *******************************************************************************************\n", devicename );
-    
     SANE_Status retcode = SANE_STATUS_INVAL;
     hpaioScanner_t hpaio = 0;
     int r;
@@ -2114,6 +2113,7 @@
     char devname[256];
     MsgAttributes ma;
 
+    DBG( 0,  "\nhpaio:sane_hpaio_open(%s) *******************************************************************************************\n", devicename );
     hpaio = hpaioFindScanner( devicename );
     
     if( hpaio )
@@ -2878,6 +2878,8 @@
     IP_IMAGE_TRAITS traits;
     IP_XFORM_SPEC xforms[IP_MAX_XFORMS], * pXform = xforms;
     WORD wResult;
+    int lines, pixelsPerLine;
+    int log_output;
     
     DBG( 0,  "\nhpaio: sane_hpaio_start() ******************************************************************************************* \n" );
     
@@ -2953,8 +2955,6 @@
 
     //    if( hpaio->scannerType == SCANNER_TYPE_SCL )
     //    {
-        int lines, pixelsPerLine;
-
         /* Inquire exact image dimensions. */
         if( SclInquire( hpaio->deviceid, hpaio->scan_channelid, SCL_CMD_INQUIRE_DEVICE_PARAMETER, SCL_INQ_NUMBER_OF_SCAN_LINES,
                         &lines, 0, 0 ) == SANE_STATUS_GOOD )
@@ -2979,9 +2979,9 @@
         MfpdtfReadStart( hpaio->mfpdtf );  /* inits mfpdtf */
         
 #ifdef HPAIO_DEBUG
-        int log_output=1;
+        log_output=1;
 #else
-        int log_output=0;
+        log_output=0;
 #endif        
 
         if( log_output )
