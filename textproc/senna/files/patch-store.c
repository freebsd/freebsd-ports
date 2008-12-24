--- ./lib/store.c.orig	2008-06-12 14:18:12.000000000 +0900
+++ ./lib/store.c	2008-11-13 18:21:14.000000000 +0900
@@ -20,6 +20,7 @@
 #include "sym.h"
 #include "store.h"
 #include "ctx.h"
+#include <stddef.h>
 #include <string.h>
 
 /* rectangular arrays */
@@ -1735,10 +1736,12 @@
 sen_vgram_buf_add(sen_vgram_buf *b, sen_id tid)
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
 
