--- ./src/hbuf.c.orig	Fri Apr 14 19:19:10 2006
+++ ./src/hbuf.c	Sat May  6 20:05:46 2006
@@ -252,6 +252,9 @@
   hbuf_block *blk;
   guchar last_persist_prefixflags = 0;
   GList *last_persist;  // last persistent flags
+  int maxlen;
+  hbb_line **array;
+  hbb_line **array_elt;
 
   // To be able to correctly highlight multi-line messages,
   // we need to look at the last non-null prefix, which should be the first
@@ -266,12 +269,11 @@
     last_persist = g_list_previous(last_persist);
   }
 
-  hbb_line **array = g_new0(hbb_line*, n);
-  hbb_line **array_elt = array;
+  array = g_new0(hbb_line*, n);
+  array_elt = array;
 
   for (i=0 ; i < n ; i++) {
     if (hbuf) {
-      int maxlen;
       blk = (hbuf_block*)(hbuf->data);
       maxlen = blk->ptr_end - blk->ptr;
       *array_elt = (hbb_line*)g_new(hbb_line, 1);
