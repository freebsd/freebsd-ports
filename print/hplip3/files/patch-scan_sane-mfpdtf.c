--- scan/sane/mfpdtf.c.orig	Tue May 23 15:07:49 2006
+++ scan/sane/mfpdtf.c	Tue May 23 15:10:30 2006
@@ -156,10 +156,10 @@
 
 int MfpdtfReadService( Mfpdtf_t mfpdtf )
 {
-    DBG( 0, "MfpdtfReadService() ______________________________ deviceid=%d, channelid=%d ______________________________\n", mfpdtf->deviceid, mfpdtf->channelid );
-    
     int result = 0;
-    int datalen, blockLength, headerLength;
+    int datalen, blockLength, headerLength, r;
+
+    DBG( 0, "MfpdtfReadService() ______________________________ deviceid=%d, channelid=%d ______________________________\n", mfpdtf->deviceid, mfpdtf->channelid );
 
     if( mfpdtf->read.fixedBlockBytesRemaining <= 0 )
     {
@@ -171,7 +171,7 @@
         
         //READ( &mfpdtf->read.fixedHeader, datalen );
         
-        int r = MfpdtfReadGeneric( mfpdtf, (unsigned char *)&mfpdtf->read.fixedHeader, datalen );
+        r = MfpdtfReadGeneric( mfpdtf, (unsigned char *)&mfpdtf->read.fixedHeader, datalen );
 
         if( r!= datalen )
         {
@@ -209,7 +209,7 @@
             
             //READ( mfpdtf->read.pVariantHeader, datalen );
             
-            int r = MfpdtfReadGeneric( mfpdtf, (unsigned char *)mfpdtf->read.pVariantHeader, datalen );
+            r = MfpdtfReadGeneric( mfpdtf, (unsigned char *)mfpdtf->read.pVariantHeader, datalen );
     
             if( r!= datalen )
             {
@@ -261,7 +261,7 @@
             
             //READ( &id, datalen );
             
-            int r = MfpdtfReadGeneric( mfpdtf, (unsigned char *)&id, datalen );
+            r = MfpdtfReadGeneric( mfpdtf, (unsigned char *)&id, datalen );
     
             if( r!= datalen )
             {
@@ -280,7 +280,7 @@
                 DBG( 0, "********************************** RASTER RECORD **********************************.\n" );
                 //READ( &mfpdtf->read.imageRasterDataHeader, datalen );
                 
-                int r = MfpdtfReadGeneric( mfpdtf, (unsigned char *)&mfpdtf->read.imageRasterDataHeader, datalen );
+                r = MfpdtfReadGeneric( mfpdtf, (unsigned char *)&mfpdtf->read.imageRasterDataHeader, datalen );
     
                 if( r!= datalen )
                 {
@@ -302,7 +302,7 @@
                 DBG( 0, "********************************** SOP RECORD **********************************.\n" );
                 //READ( &mfpdtf->read.imageStartPageRecord, datalen );
 
-                int r = MfpdtfReadGeneric( mfpdtf, (unsigned char *)&mfpdtf->read.imageStartPageRecord, datalen );
+                r = MfpdtfReadGeneric( mfpdtf, (unsigned char *)&mfpdtf->read.imageStartPageRecord, datalen );
     
                 if( r!= datalen )
                 {
@@ -322,7 +322,7 @@
                 DBG( 0, "********************************** EOP RECORD **********************************.\n" );
                 //READ( &mfpdtf->read.imageEndPageRecord, datalen );
                 
-                int r = MfpdtfReadGeneric( mfpdtf, (unsigned char *)&mfpdtf->read.imageEndPageRecord, datalen );
+                r = MfpdtfReadGeneric( mfpdtf, (unsigned char *)&mfpdtf->read.imageEndPageRecord, datalen );
     
                 if( r!= datalen )
                 {
