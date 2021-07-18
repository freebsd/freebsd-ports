--- luatexdir/image/writeimg.h.orig	2015-03-20 07:59:58 UTC
+++ luatexdir/image/writeimg.h
@@ -27,7 +27,7 @@
 #  include "pdf/pdfpage.h"
 
 typedef image_dict *idict_entry;
-idict_entry *idict_array;
+extern idict_entry *idict_array;
 
 void new_img_pdfstream_struct(image_dict *);
 image *new_image(void);
