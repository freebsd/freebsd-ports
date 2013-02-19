--- ./libbsm/bsm_io.c.orig	2013-02-18 21:07:28.000000000 -0500
+++ ./libbsm/bsm_io.c	2013-02-18 21:07:38.000000000 -0500
@@ -949,7 +949,7 @@
 {
 
 	print_tok_type(fp, tok->id, "header", oflags);
-	if (oflags & AU_OFLAG_RAW) {
+	if (oflags & AU_OFLAG_XML) {
 		open_attr(fp, "version");
 		print_1_byte(fp, tok->tt.hdr32.version, "%u");
 		close_attr(fp);
