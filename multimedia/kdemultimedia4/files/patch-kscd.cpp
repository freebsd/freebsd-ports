--- kscd/kscd.cpp	Sun Dec  2 15:08:44 2001
+++ kscd/kscd.cpp.new	Sun Dec  2 15:10:04 2001
@@ -1313,7 +1313,6 @@
 /*
  * cdMode
  *
- * - 'No disc' handling is missing
  * - Data discs not recognized as data discs.
  *
  */
@@ -1329,7 +1328,7 @@
   if( sss == 2 )
       have_new_cd = true;
 
-  if(sss < 0)
+  if(sss < 0 || sss == WM_CDS_NO_DISC)
   {
         if(cddrive_is_ok && (sss != WM_ERR_SCSI_INQUIRY_FAILED))
         {
