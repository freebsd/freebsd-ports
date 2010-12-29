--- ./xbmc/lib/cximage-6.0/raw/dcr.c.orig	2009-05-16 12:01:35.000000000 +0200
+++ ./xbmc/lib/cximage-6.0/raw/dcr.c	2010-12-01 12:17:34.252898220 +0100
@@ -144,8 +144,12 @@
 
 		//!!! set return point for error handling
 		if (setjmp (dcr.failure)) {
-			if (fileno(dcr.obj_) > 2) (*dcr.ops_->close_)(dcr.obj_);
-			if (fileno(ofp) > 2) fclose(ofp);
+#if !defined(__FreeBSD__)
+			if (fileno(dcr.obj_) > 2)
+				(*dcr.ops_->close_)(dcr.obj_);
+#endif				
+			if (fileno(ofp) > 2)
+				fclose(ofp);
 			status = 1;
 			goto cleanup;
 		}
