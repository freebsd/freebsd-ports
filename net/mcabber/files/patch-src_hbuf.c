$FreeBSD$

--- src/hbuf.c.orig
+++ src/hbuf.c
@@ -70,12 +70,12 @@
     // Set p_hbuf to the end of the list, to speed up history loading
     // (or CPU time will be used by g_list_last() for each line)
     hbuf = *p_hbuf = g_list_last(*p_hbuf);
-    hbuf_block *hbuf_b_prev = hbuf->data;
+    { hbuf_block *hbuf_b_prev = hbuf->data;
     hbuf_block_elt->ptr    = hbuf_b_prev->ptr_end;
     hbuf_block_elt->flags  = HBB_FLAG_PERSISTENT;
     hbuf_block_elt->ptr_end_alloc = hbuf_b_prev->ptr_end_alloc;
     g_list_append(*p_hbuf, hbuf_block_elt);
-  }
+  }}
 
   if (strlen(text) >= HBB_BLOCKSIZE) {
     // Too long
