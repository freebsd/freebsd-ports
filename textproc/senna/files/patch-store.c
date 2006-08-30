--- lib/store.c.orig	Tue Aug 29 03:00:23 2006
+++ lib/store.c	Tue Aug 29 16:42:28 2006
@@ -18,6 +18,7 @@
 #include "str.h"
 #include "inv.h"
 #include "store.h"
+#include <stddef.h>
 #include <string.h>
 
 static int len_sum = 0;
@@ -60,10 +61,12 @@
 sen_store_buf_add(sen_store_buf *b, sen_id tid)
 {
   uint8_t dummybuf[8], *dummyp;
+  ptrdiff_t pd;
   if (b->tvp < b->tve) { *b->tvp++ = tid; }
   dummyp = dummybuf;
   SEN_B_ENC(tid, dummyp);
-  simple_sum += dummyp - dummybuf;
+  pd = dummyp - dummybuf;
+  simple_sum += (int)pd;
   return sen_success;
 }
 
