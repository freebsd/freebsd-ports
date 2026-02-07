--- lib/Senna.xs.orig	2007-03-17 01:45:57.000000000 +0900
+++ lib/Senna.xs	2009-04-29 23:58:36.000000000 +0900
@@ -24,6 +24,108 @@
 #define SEN_SYM_MAX_KEY_LENGTH 0xffff
 #endif
 
+typedef uint8_t byte;
+
+#ifndef SEN_SYM_MAX_SEGMENT
+#define SEN_SYM_MAX_SEGMENT 0x400
+#endif
+
+typedef enum {
+  sen_io_auto,
+  sen_io_manual
+} sen_io_mode;
+
+typedef struct {
+  void *map;
+  uint32_t nref;
+  uint32_t count;
+#if defined(WIN32) && defined(WIN32_FMO_EACH)
+  HANDLE fmo;
+#endif /* defined(WIN32) && defined(WIN32_FMO_EACH) */
+} sen_io_mapinfo;
+
+typedef struct _sen_io sen_io;
+
+struct _sen_io {
+  char path[PATH_MAX];
+  struct _sen_io_header *header;
+  byte *user_header;
+  sen_io_mapinfo *maps;
+  uint32_t *nrefs;
+  uint32_t base;
+  uint32_t base_seg;
+  sen_io_mode mode;
+  uint32_t cache_size;
+  struct _sen_io_fileinfo *fis;
+  uint32_t nmaps;
+  uint32_t count;
+  uint8_t flags;
+};
+
+struct _sen_sym {
+  uint8_t v08p;
+  sen_io *io;
+  struct sen_sym_header *header;
+  uint32_t flags;
+  sen_encoding encoding;
+  uint32_t key_size;
+  uint32_t nref;
+  uint32_t *lock;
+  void *keyaddrs[SEN_SYM_MAX_SEGMENT];
+  void *pataddrs[SEN_SYM_MAX_SEGMENT];
+  void *sisaddrs[SEN_SYM_MAX_SEGMENT];
+};
+
+#define SEN_SET_MAX_CHUNK 22
+
+typedef pthread_mutex_t sen_mutex;
+
+typedef struct _sen_array sen_array;
+// #define SEN_ARRAY_W 2
+#define SEN_ARRAY_W 0
+#define SEN_ARRAY_R(i) (1<<((i)<<SEN_ARRAY_W))
+#define SEN_ARRAY_S (SEN_ARRAY_R(1)-1)
+#define SEN_ARRAY_N (32>>SEN_ARRAY_W)
+
+struct _sen_array {
+  sen_ctx *ctx;
+  sen_id max;
+  uint16_t element_size;
+  uint16_t flags;
+  sen_mutex lock;
+  void *elements[SEN_ARRAY_N];
+};
+
+struct _sen_set {
+  uint32_t key_size;
+  uint32_t value_size;
+  uint32_t entry_size;
+  uint32_t max_offset;
+  int32_t n_entries;
+  uint32_t n_garbages;
+  //  uint32_t curr_entry;
+  //  uint32_t curr_chunk;
+  unsigned int max_n_subrecs;
+  unsigned int record_size;
+  unsigned int subrec_size;
+  sen_rec_unit record_unit;
+  sen_rec_unit subrec_unit;
+  uint8_t arrayp;
+  sen_set_eh garbages;
+  sen_set_eh *index;
+  sen_ctx *ctx;
+  sen_sym *keys;
+  sen_recordh *curr_rec;
+  sen_set_cursor *cursor;
+  int limit;
+  sen_recordh *sorted;
+  void *userdata;
+  sen_id subrec_id;
+  //  byte *chunks[SEN_SET_MAX_CHUNK + 1];
+
+  sen_array a;
+};
+
 /* This is defined in senna's snip.h. */
 #ifndef MAX_SNIP_RESULT_COUNT
 #define MAX_SNIP_RESULT_COUNT 8U
@@ -212,6 +314,9 @@
     }
 }
 
+struct _sen_set;
+/* typedef struct _sen_set sen_set; */
+
 static int
 sen_sort_optarg_cb(sen_records *r1, const sen_recordh *a,
     sen_records *r2, const sen_recordh *b, void *args)
@@ -231,6 +336,11 @@
 
     cb_args = (AV *) compar_args[1];
 
+/* sen_rc sen_sym_info(sen_sym *sym, int *key_size, unsigned *flags,
+   sen_encoding *encoding, unsigned *nrecords, unsigned *file_size); */
+/* typedef struct _sen_sym sen_sym; */
+/* typedef sen_set sen_records; */
+/* sen_set.sen_sym* keys */
     sen_sym_info(r1->keys, &key_size, NULL, NULL, NULL, NULL);
     if (key_size == SEN_VARCHAR_KEY) {
         char key[SEN_MAX_KEY_SIZE];
@@ -519,10 +629,18 @@
         sen_rc rc;
     PPCODE:
         index = XS_STATE(sen_index *, self);
+/*
+sen_rc sen_index_info(sen_index *i, int *key_size, int *flags,
+                      int *initial_n_segments, sen_encoding *encoding,
+                      unsigned *nrecords_keys, unsigned *file_size_keys,
+                      unsigned *nrecords_lexicon, unsigned *file_size_lexicon,
+                      unsigned long long *inv_seg_size,
+                      unsigned long long *inv_chunk_size);
+ */
         rc = sen_index_info(index,
             &key_size, &flags, &initial_n_segments, &encoding,
             &nrecords_keys, &file_size_keys, &nrecords_lexicon,
-            &file_size_lexicon, &inv_seg_size, &inv_chunk_size
+            &file_size_lexicon, (unsigned long long*)&inv_seg_size, (unsigned long long*)&inv_chunk_size
         );
 
         if (rc != sen_success)
@@ -910,10 +1028,12 @@
         sen_records_rewind(r);
         sen_record_info(r, sen_records_curr_rec(r), NULL, 0, &key_size,
             NULL, NULL, NULL, NULL);
+/* int sen_records_find(sen_records *r, const void *key);
+ */
         if (key_size == SEN_INT_KEY) {
-            RETVAL = sen_records_find(r, (void *) SvIV(key));
+            RETVAL = sen_records_find(r, (const void *) SvIV(key));
         } else {
-            RETVAL = sen_records_find(r, (void *) SvPV(key, len));
+            RETVAL = sen_records_find(r, (const void *) SvPV(key, len));
         }
         sen_records_rewind(r);
     OUTPUT:
