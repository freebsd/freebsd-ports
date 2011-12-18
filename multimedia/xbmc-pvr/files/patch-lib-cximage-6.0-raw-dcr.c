--- lib/cximage-6.0/raw/dcr.c.orig
+++ lib/cximage-6.0/raw/dcr.c
@@ -144,7 +144,9 @@ int DCR_CLASS main (int argc, char **arg
 
 		//!!! set return point for error handling
 		if (setjmp (dcr.failure)) {
+#if !defined(__FreeBSD__)
 			if (fileno(dcr.obj_) > 2) (*dcr.ops_->close_)(dcr.obj_);
+#endif
 			if (fileno(ofp) > 2) fclose(ofp);
 			status = 1;
 			goto cleanup;
