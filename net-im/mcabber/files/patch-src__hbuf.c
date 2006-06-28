--- ./src/hbuf.c.orig	Thu Jun 22 10:30:34 2006
+++ ./src/hbuf.c	Thu Jun 22 10:31:06 2006
@@ -253,6 +253,7 @@
   hbuf_block *blk;
   guchar last_persist_prefixflags = 0;
   GList *last_persist;  // last persistent flags
+  int maxlen;
   hbb_line **array, **array_elt;
 
   // To be able to correctly highlight multi-line messages,
@@ -273,7 +274,6 @@
 
   for (i = 0 ; i < n ; i++) {
     if (hbuf) {
-      int maxlen;
       blk = (hbuf_block*)(hbuf->data);
       maxlen = blk->ptr_end - blk->ptr;
       *array_elt = (hbb_line*)g_new(hbb_line, 1);
