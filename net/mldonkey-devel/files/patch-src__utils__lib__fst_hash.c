--- ../mldonkey.orig/src/utils/lib/fst_hash.c	Mon Aug  1 20:53:33 2005
+++ src/utils/lib/fst_hash.c	Sat Dec 10 17:44:06 2005
@@ -181,9 +181,9 @@
 #include "caml/mlvalues.h"
 
 /* returns checksum of fzhash */
-uint16 fst_hash_checksum (unsigned char *hash)
+unsigned short fst_hash_checksum (unsigned char *hash)
 {
-        uint16 sum = 0;
+        unsigned short sum = 0;
         int i;
 
         /* calculate 2 byte checksum used in the URL from 20 byte fthash */
