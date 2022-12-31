--- texk/xdvik/util.h.orig	2022-02-13 22:53:37 UTC
+++ texk/xdvik/util.h
@@ -74,6 +74,9 @@ extern void prep_fd(int fd, wide_bool noblock);
 
 struct bitmap; /* forward declaration */
 extern void alloc_bitmap(struct bitmap *);
+extern void clear_bitmap(struct bitmap *);
+extern void fill_bitmap(struct bitmap *);
+extern void order_reverse_bitmap(struct bitmap *);
 
 extern char *my_realpath(const char *path, char *real);
 #ifdef HAVE_REALPATH
@@ -150,6 +153,7 @@ typedef hash_table_type hashTableT; /* from kpathsea *
 extern Boolean find_str_int_hash(hashTableT *hashtable, const char *key, size_t *val);
 extern void put_str_int_hash(hashTableT *hashtable, const char *key, size_t val);
 
+#if FREETYPE || PS
 
 /*
  *	AVL tree structures.
@@ -167,6 +171,8 @@ struct avl {		/* generic data structure */
 };
 
 extern struct avl *avladd(const char *, size_t, struct avl **, size_t);
+
+#endif /* FREETYPE || PS */
 
 
 extern Boolean copy_file(const char *from, const char *to);
