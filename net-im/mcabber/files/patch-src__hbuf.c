--- ./src/hbuf.c.orig	Sat Dec 16 21:05:39 2006
+++ ./src/hbuf.c	Sat Jan 13 03:02:55 2007
@@ -250,6 +250,7 @@
   hbuf_block *blk;
   guchar last_persist_prefixflags = 0;
   GList *last_persist;  // last persistent flags
+  int maxlen;
   hbb_line **array, **array_elt;
 
   // To be able to correctly highlight multi-line messages,
@@ -270,7 +271,6 @@
 
   for (i = 0 ; i < n ; i++) {
     if (hbuf) {
-      int maxlen;
       blk = (hbuf_block*)(hbuf->data);
       maxlen = blk->ptr_end - blk->ptr;
       *array_elt = (hbb_line*)g_new(hbb_line, 1);
