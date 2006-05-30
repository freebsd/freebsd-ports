--- src/utils/lib/fst_hash.c.orig	Mon Nov  1 12:23:02 2004
+++ src/utils/lib/fst_hash.c	Thu Apr 20 02:45:46 2006
@@ -179,6 +179,7 @@
 
 
 #include "caml/mlvalues.h"
+#define uint16 unsigned short int
 
 /* returns checksum of fzhash */
 uint16 fst_hash_checksum (unsigned char *hash)
@@ -337,4 +338,4 @@
 value fst_hash_checksum_ml(value digest)
 {
   return Val_int(fst_hash_checksum(String_val(digest)));
-}
\ No newline at end of file
+}
