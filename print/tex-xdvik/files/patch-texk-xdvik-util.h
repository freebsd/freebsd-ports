--- texk/xdvik/util.h.orig	2014-09-02 18:41:34.000000000 +0900
+++ texk/xdvik/util.h	2015-01-31 21:02:18.000000000 +0900
@@ -73,6 +73,9 @@
 
 struct bitmap; /* forward declaration */
 extern void alloc_bitmap(struct bitmap *);
+extern void clear_bitmap(struct bitmap *);
+extern void fill_bitmap(struct bitmap *);
+extern void order_reverse_bitmap(struct bitmap *);
 
 extern char *my_realpath(const char *path, char *real);
 #ifdef HAVE_REALPATH
@@ -150,6 +153,7 @@
 extern Boolean find_str_int_hash(hashTableT *hashtable, const char *key, size_t *val);
 extern void put_str_int_hash(hashTableT *hashtable, const char *key, size_t val);
 
+#if FREETYPE || PS
 
 /*
  *	AVL tree structures.
@@ -168,6 +172,8 @@
 
 extern struct avl *avladd(const char *, size_t, struct avl **, size_t);
 
+#endif /* FREETYPE || PS */
+
 
 extern Boolean copy_file(const char *from, const char *to);
 extern Boolean copy_fp(FILE *in, FILE *out);
