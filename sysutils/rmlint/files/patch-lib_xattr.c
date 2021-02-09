--- lib/xattr.c.orig	2020-12-06 15:39:50 UTC
+++ lib/xattr.c
@@ -209,7 +209,7 @@ static int rm_xattr_del(RmFile *file, const char *key,
 //  ACTUAL API FUNCTIONS  //
 ////////////////////////////
 
-int rm_xattr_write_hash(RmFile *file, RmSession *session) {
+int rm_xattr_write_hash(__attribute__((unused)) RmFile *file, __attribute__((unused)) RmSession *session) {
     g_assert(file);
     g_assert(file->digest);
     g_assert(session);
@@ -236,7 +236,7 @@ int rm_xattr_write_hash(RmFile *file, RmSession *sessi
     return 0;
 }
 
-gboolean rm_xattr_read_hash(RmFile *file, RmSession *session) {
+gboolean rm_xattr_read_hash(__attribute__((unused)) RmFile *file, __attribute__((unused)) RmSession *session) {
     g_assert(file);
     g_assert(session);
 
@@ -287,7 +287,7 @@ gboolean rm_xattr_read_hash(RmFile *file, RmSession *s
 #endif
 }
 
-int rm_xattr_clear_hash(RmFile *file, RmSession *session) {
+int rm_xattr_clear_hash(__attribute__((unused)) RmFile *file, __attribute__((unused)) RmSession *session) {
     g_assert(file);
     g_assert(session);
 
@@ -316,6 +316,8 @@ int rm_xattr_clear_hash(RmFile *file, RmSession *sessi
 
 #if HAVE_XATTR
 
+#if HAVE_XATTR
+
 GHashTable *rm_xattr_list(const char *path, bool follow_symlinks) {
     const size_t buf_size = 4096;
     const size_t val_size = 1024;
@@ -484,5 +486,7 @@ int rm_xattr_mark_deduplicated(const char *path, bool 
     g_hash_table_destroy(map);
     return result;
 }
+
+#endif
 
 #endif
