--- ./index/build_in.c.orig	1999-11-01 21:19:27.000000000 +0000
+++ ./index/build_in.c	2014-01-27 21:40:18.000000000 +0000
@@ -44,8 +44,12 @@
 extern struct stat excstbuf;
 extern struct stat incstbuf;
 
+void build_hash();
+void init_hash_table();
 void insert_h();
 void insert_index();
+void merge_in(FILE *, FILE *, FILE *);
+void remove_filename(int, int);
 
 extern int ICurrentFileOffset;
 extern int NextICurrentFileOffset;
@@ -124,7 +128,7 @@
 extern int HashTableSize;
 struct token **hash_table; /*[MAX_64K_HASH];*/
 
-build_index()
+void build_index()
 {
 	int	i;
 
@@ -598,7 +602,7 @@
 #endif
 }
 
-traverse1()
+void traverse1()
 {
     FILE *i1, *i2, *i3;
     int ret;
@@ -780,7 +784,7 @@
 input: a set of filenames in name_list[], a partition table p_table[]
 output: a hash table hash_table[].
 -----------------------------------------------------------------------*/
-build_hash()
+void build_hash()
 {
     int	fd;                          /* opened file number */
     int  i, pn;                  /* pn: current partition */
@@ -1229,7 +1233,7 @@
     my_free(buffer_begin, BLOCK_SIZE + 10);
 }
 
-init_hash_table()
+void init_hash_table()
 {
     int i;
 
@@ -1480,7 +1484,7 @@
 extern unsigned char *merge_index_buf;
 
 /* merge index file f1 and f2, then put the result in index file f3 */
-merge_in(f1, f2, f3)
+void merge_in(f1, f2, f3)
 FILE *f1, *f2, *f3;
 {
     int src_mark, dest_mark;
@@ -1858,7 +1862,7 @@
     return;
 }
 
-remove_filename(fileindex, new_partition)
+void remove_filename(fileindex, new_partition)
 	int	fileindex, new_partition;
 {
 	if ((fileindex < 0) || (fileindex >= MaxNum24bPartition)) return;
