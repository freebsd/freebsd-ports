
$FreeBSD$

--- rtp.c.orig	Tue Nov 25 23:15:28 2003
+++ rtp.c	Fri Jan 30 01:47:34 2004
@@ -114,7 +114,7 @@
 {
 	switch(buf & TYPE_MASK) {
 	case TYPE_DONTSEND:
-		return 0;
+		return 2;
 		break;
 	case TYPE_SILENCE:
 		return 4;
@@ -1028,19 +1028,6 @@
 		while((f = ast_smoother_read(rtp->smoother)))
 			ast_rtp_raw_write(rtp, f, codec);
 		break;
-	case AST_FORMAT_G729A:
-		if (!rtp->smoother) {
-			rtp->smoother = ast_smoother_new(20);
-		}
-		if (!rtp->smoother) {
-			ast_log(LOG_WARNING, "Unable to create g729 smoother :(\n");
-			return -1;
-		}
-		ast_smoother_feed(rtp->smoother, _f);
-		
-		while((f = ast_smoother_read(rtp->smoother)))
-			ast_rtp_raw_write(rtp, f, codec);
-		break;
 	case AST_FORMAT_GSM:
 		if (!rtp->smoother) {
 			rtp->smoother = ast_smoother_new(33);
@@ -1071,6 +1058,7 @@
 	case AST_FORMAT_H261:
 	case AST_FORMAT_H263:
 	case AST_FORMAT_G723_1:
+	case AST_FORMAT_G729A:
 	case AST_FORMAT_SPEEX:
 	        // Don't buffer outgoing frames; send them one-per-packet:
 		if (_f->offset < hdrlen) {
