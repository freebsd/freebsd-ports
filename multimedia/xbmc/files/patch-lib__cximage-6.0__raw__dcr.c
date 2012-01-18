--- ./lib/cximage-6.0/raw/dcr.c.orig	2011-12-23 04:12:21.000000000 +0100
+++ ./lib/cximage-6.0/raw/dcr.c	2012-01-02 10:14:38.000000000 +0100
@@ -144,7 +144,9 @@
 
 		//!!! set return point for error handling
 		if (setjmp (dcr.failure)) {
+#if !defined(__FreeBSD__)
 			if (fileno(dcr.obj_) > 2) (*dcr.ops_->close_)(dcr.obj_);
+#endif
 			if (fileno(ofp) > 2) fclose(ofp);
 			status = 1;
 			goto cleanup;
