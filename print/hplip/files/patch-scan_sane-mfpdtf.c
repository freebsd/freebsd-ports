--- scan/sane/mfpdtf.c.orig	Sat Nov 11 00:22:14 2006
+++ scan/sane/mfpdtf.c	Mon Dec 25 01:43:52 2006
@@ -157,7 +157,7 @@
 int MfpdtfReadService( Mfpdtf_t mfpdtf )
 {
     int result = 0;
-    int datalen, blockLength, headerLength;
+    int datalen, blockLength, headerLength, r;
 
     if( mfpdtf->read.fixedBlockBytesRemaining <= 0 )
     {
@@ -169,7 +169,7 @@
         
         //READ( &mfpdtf->read.fixedHeader, datalen );
         
-        int r = MfpdtfReadGeneric( mfpdtf, (unsigned char *)&mfpdtf->read.fixedHeader, datalen );
+        r = MfpdtfReadGeneric( mfpdtf, (unsigned char *)&mfpdtf->read.fixedHeader, datalen );
 
         if( r!= datalen )
         {
@@ -207,7 +207,7 @@
             
             //READ( mfpdtf->read.pVariantHeader, datalen );
             
-            int r = MfpdtfReadGeneric( mfpdtf, (unsigned char *)mfpdtf->read.pVariantHeader, datalen );
+            r = MfpdtfReadGeneric( mfpdtf, (unsigned char *)mfpdtf->read.pVariantHeader, datalen );
     
             if( r!= datalen )
             {
@@ -259,7 +259,7 @@
             
             //READ( &id, datalen );
             
-            int r = MfpdtfReadGeneric( mfpdtf, (unsigned char *)&id, datalen );
+            r = MfpdtfReadGeneric( mfpdtf, (unsigned char *)&id, datalen );
     
             if( r!= datalen )
             {
@@ -296,7 +296,7 @@
                 datalen = sizeof( mfpdtf->read.imageStartPageRecord );
 		//                DBG( 0, "Reading start of page record.\n" );
 		//                DBG( 0, "********************************** SOP RECORD **********************************.\n" );
-                int r = MfpdtfReadGeneric( mfpdtf, (unsigned char *)&mfpdtf->read.imageStartPageRecord, datalen );
+                r = MfpdtfReadGeneric( mfpdtf, (unsigned char *)&mfpdtf->read.imageStartPageRecord, datalen );
     
                 if( r!= datalen )
                 {
@@ -314,7 +314,7 @@
                 datalen = sizeof( mfpdtf->read.imageEndPageRecord );
 		//                DBG( 0, "Reading end of page record.\n" );
 		//                DBG( 0, "********************************** EOP RECORD **********************************.\n" );
-                int r = MfpdtfReadGeneric( mfpdtf, (unsigned char *)&mfpdtf->read.imageEndPageRecord, datalen );
+                r = MfpdtfReadGeneric( mfpdtf, (unsigned char *)&mfpdtf->read.imageEndPageRecord, datalen );
     
                 if( r!= datalen )
                 {
