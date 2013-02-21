diff -Nur src/cache.c src/cache.c
--- src/cache.c	2013-02-19 23:54:34.000000000 +0200
+++ src/cache.c	2013-02-19 23:50:31.000000000 +0200
@@ -88,13 +88,22 @@
 }
 
 struct prelink_entry *
+#if __LINUX__
 prelink_find_entry (const char *filename, const struct stat64 *stp,
 		    int insert)
+#else
+prelink_find_entry (const char *filename, const struct stat *stp,
+		    int insert)
+#endif
 {
   struct prelink_entry e, *ent = NULL;
   void **filename_slot, *dummy = NULL;
   void **devino_slot = NULL;
+#if __LINUX__
   struct stat64 st;
+#else
+  struct stat st;
+#endif
   char *canon_filename = NULL;
 
   e.filename = filename;
@@ -113,7 +122,11 @@
   if (! stp)
     {
       canon_filename = prelink_canonicalize (filename, &st);
+#if __LINUX__
       if (canon_filename == NULL && stat64 (filename, &st) < 0)
+#else
+      if (canon_filename == NULL && stat (filename, &st) < 0)
+#endif
 	{
 	  error (0, errno, "Could not stat %s", filename);
 	  if (insert)
@@ -236,7 +249,11 @@
   struct prelink_entry e, *ent = NULL;
   void **filename_slot, *dummy = NULL;
   void **devino_slot = &dummy;
+#if __LINUX__
   struct stat64 st;
+#else
+  struct stat st;
+#endif
   uint32_t ctime = 0, mtime = 0;
   char *canon_filename = NULL;
 
@@ -358,7 +375,11 @@
 prelink_load_cache (void)
 {
   int fd, i, j;
+#if __LINUX__
   struct stat64 st;
+#else
+  struct stat st;
+#endif
   struct prelink_cache *cache;
   struct prelink_entry **ents;
   size_t cache_size;
@@ -368,7 +389,11 @@
   if (fd < 0)
     return 0; /* The cache does not exist yet.  */
 
+#if __LINUX__
   if (fstat64 (fd, &st) < 0
+#else
+  if (fstat (fd, &st) < 0
+#endif
       || st.st_size == 0)
     {
       close (fd);
@@ -670,7 +695,7 @@
 
   size_t prelink_cache_len = strlen (prelink_cache);
   char prelink_cache_tmp [prelink_cache_len + sizeof (".XXXXXX")];
-  memcpy (mempcpy (prelink_cache_tmp, prelink_cache, prelink_cache_len),
+  memcpy (memcpy (prelink_cache_tmp, prelink_cache, prelink_cache_len)+prelink_cache_len,
 	  ".XXXXXX", sizeof (".XXXXXX"));
   fd = mkstemp (prelink_cache_tmp);
   if (fd < 0)
