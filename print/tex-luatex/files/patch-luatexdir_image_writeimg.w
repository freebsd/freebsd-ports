--- luatexdir/image/writeimg.w.orig	2015-03-20 07:59:58 UTC
+++ luatexdir/image/writeimg.w
@@ -125,6 +125,8 @@
 #define HEADER_PDF "%PDF-1."
 #define MAX_HEADER (sizeof(HEADER_PNG)-1)
 
+idict_entry *idict_array;
+
 static void check_type_by_header(image_dict * idict)
 {
     int i;
