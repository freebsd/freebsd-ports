--- ./src/hbuf.c.orig	Sun Aug 13 23:01:59 2006
+++ ./src/hbuf.c	Mon Aug 14 10:15:38 2006
@@ -252,6 +252,7 @@
   hbuf_block *blk;
   guchar last_persist_prefixflags = 0;
   GList *last_persist;  // last persistent flags
+  int maxlen;
   hbb_line **array, **array_elt;
 
   // To be able to correctly highlight multi-line messages,
@@ -272,7 +273,6 @@
 
   for (i = 0 ; i < n ; i++) {
     if (hbuf) {
-      int maxlen;
       blk = (hbuf_block*)(hbuf->data);
       maxlen = blk->ptr_end - blk->ptr;
       *array_elt = (hbb_line*)g_new(hbb_line, 1);
