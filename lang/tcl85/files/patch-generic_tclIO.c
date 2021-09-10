https://core.tcl-lang.org/tcl/info/24b9181478

--- ../generic/tclIO.c.orig	2020-12-11 17:46:22 UTC
+++ ../generic/tclIO.c
@@ -3765,6 +3765,7 @@ Write(
 				/* State info for channel */
     char *nextNewLine = NULL;
     int endEncoding, saved = 0, total = 0, flushed = 0, needNlFlush = 0;
+    char safe[BUFFER_PADDING];
 
     if (srcLen) {
         WillWrite(chanPtr);
@@ -3783,7 +3784,7 @@ Write(
 
     while (srcLen + saved + endEncoding > 0) {
 	ChannelBuffer *bufPtr;
-	char *dst, safe[BUFFER_PADDING];
+	char *dst;
 	int result, srcRead, dstLen, dstWrote, srcLimit = srcLen;
 
 	if (nextNewLine) {
