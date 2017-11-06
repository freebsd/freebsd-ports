# Correct a string that should be const
#
--- src/sis_utility.c.orig	2015-08-29 23:34:25 UTC
+++ src/sis_utility.c
@@ -850,7 +850,7 @@ SISGetMergedModeDetails(ScrnInfoPtr pScr
  ***********************************/
 
 static void
-sisutil_prepare_string(xSiSCtrlCommandReply *sdcbuf, char *mystring)
+sisutil_prepare_string(xSiSCtrlCommandReply *sdcbuf, const char *mystring)
 {
    int slen = 0;
    sdcbuf->sdc_buffer[0] = 0;
