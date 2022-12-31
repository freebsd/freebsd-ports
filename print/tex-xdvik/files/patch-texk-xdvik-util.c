--- texk/xdvik/util.c.orig	2022-02-15 20:44:41 UTC
+++ texk/xdvik/util.c
@@ -214,6 +214,7 @@ struct debug_string_options debug_options[] = {
     {  DBG_GUI,		"gui",		", " },
     {  DBG_FIND,	"find",		", " },
     {  DBG_FILES,	"files",	", " },
+    {  DBG_PTEXFNT,	"ptexfnt",	", " },
     {  DBG_ALL,		"all",		"\n" },
     /* end marker */
     {  0,		NULL,		NULL }
@@ -677,7 +678,39 @@ alloc_bitmap(struct bitmap *bitmap)
     bitmap->bits = xmalloc(size != 0 ? size : 1);
 }
 
+void
+clear_bitmap(struct bitmap *bitmap)
+{
+    memset(bitmap->bits, 0, bitmap->bytes_wide * bitmap->h);
+}
 
+void
+fill_bitmap(struct bitmap *bitmap)
+{
+    memset(bitmap->bits, 0xff, bitmap->bytes_wide * bitmap->h);
+}
+
+void
+order_reverse_bitmap(struct bitmap *bitmap)
+{
+    int i, size = bitmap->bytes_wide * bitmap->h;
+    unsigned char *p = (unsigned char *)bitmap->bits;
+    static unsigned char reverse_byte[0x100];
+
+    if (reverse_byte[1] == 0) {  /* init reverse_byte[] */
+	for (i=0; i<0x100; i++) {
+	    int src, dst = 0;
+	    for (src=1; src<0x100; src<<=1) {
+		dst <<= 1;
+		if (i & src) dst |= 1;
+	    }
+	    reverse_byte[i] = dst;
+	}
+    }
+
+    for (i=0; i<size; i++) p[i] = reverse_byte[p[i]];
+}
+
 #ifndef HAVE_MEMICMP
 /*
  * Case-insensitive version of memcmp().  This code assumes that the second
@@ -1568,6 +1601,8 @@ put_str_int_hash(hashTableT *hashtable, const char *ke
 }
 
 
+#if FREETYPE || PS
+
 /*
  *	General AVL tree mechanism.  Search for a node, and return it if found.
  *	Otherwise insert a node.
@@ -1698,6 +1733,8 @@ avladd(const char *key, size_t key_len, struct avl **h
 
 	return ap;
 }
+
+#endif /* FREETYPE || PS */
 
 
 /* set globals.dvi_name, globals.dvi_file.dirname and globals.dvi_file.dirlen */
