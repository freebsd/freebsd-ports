--- ./src/util/find_uid.c.orig	2011-08-29 11:39:05.000000000 -0400
+++ ./src/util/find_uid.c	2011-10-13 12:15:03.000000000 -0400
@@ -67,7 +67,7 @@
     uint32_t num=0;
     errno_t error;
 
-    ret = snprintf(path, PATHLEN, "/proc/%d/status", pid);
+    ret = snprintf(path, PATHLEN, "/compat/linux/proc/%d/status", pid);
     if (ret < 0) {
         DEBUG(1, ("snprintf failed"));
         return EINVAL;
@@ -204,7 +204,7 @@
     hash_key_t key;
     hash_value_t value;
 
-    proc_dir = opendir("/proc");
+    proc_dir = opendir("/compat/linux/proc");
     if (proc_dir == NULL) {
         ret = errno;
         DEBUG(1, ("Cannot open proc dir.\n"));
@@ -278,9 +278,8 @@
 
 errno_t get_uid_table(TALLOC_CTX *mem_ctx, hash_table_t **table)
 {
-#ifdef __linux__
     int ret;
-
+#if 1
     ret = hash_create_ex(INITIAL_TABLE_SIZE, table, 0, 0, 0, 0,
                          hash_talloc, hash_talloc_free, mem_ctx,
                          NULL, NULL);
