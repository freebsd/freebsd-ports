--- ./lib/src/libcommon.cpp.orig	2011-07-08 12:35:48.000000000 +0000
+++ ./lib/src/libcommon.cpp	2012-12-11 07:48:00.601016758 +0000
@@ -599,7 +599,7 @@
 
 int unpack_zlib(const char* arch_file_name, const char* out_file_name)
 {
-	zip::gzFile in(gzopen(arch_file_name, "rb"));
+	zip::gzFileWrapper in(gzopen(arch_file_name, "rb"));
 	if(!in) {
 		g_critical("Unable to open archive file: %s.", arch_file_name);
 		return EXIT_FAILURE;
