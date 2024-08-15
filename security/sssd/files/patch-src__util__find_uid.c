--- src/util/find_uid.c.orig	2020-03-17 13:31:28 UTC
+++ src/util/find_uid.c
@@ -72,7 +72,7 @@ static errno_t get_uid_from_pid(const pid_t pid, uid_t
     uint32_t num=0;
     errno_t error;
 
-    ret = snprintf(path, PATHLEN, "/proc/%d/status", pid);
+    ret = snprintf(path, PATHLEN, "/compat/linux/proc/%d/status", pid);
     if (ret < 0) {
         DEBUG(SSSDBG_CRIT_FAILURE, "snprintf failed\n");
         return EINVAL;
@@ -216,12 +216,12 @@ static errno_t get_active_uid_linux(hash_table_t *tabl
     struct dirent *dirent;
     int ret, err;
     pid_t pid = -1;
-    uid_t uid;
+    uid_t uid = -1;
 
     hash_key_t key;
     hash_value_t value;
 
-    proc_dir = opendir("/proc");
+    proc_dir = opendir("/compat/linux/proc");
     if (proc_dir == NULL) {
         ret = errno;
         DEBUG(SSSDBG_CRIT_FAILURE, "Cannot open proc dir.\n");
@@ -301,9 +301,8 @@ errno_t get_uid_table(TALLOC_CTX *mem_ctx, hash_table_
 
 errno_t get_uid_table(TALLOC_CTX *mem_ctx, hash_table_t **table)
 {
-#ifdef __linux__
     int ret;
-
+#if 1
     ret = hash_create_ex(INITIAL_TABLE_SIZE, table, 0, 0, 0, 0,
                          hash_talloc, hash_talloc_free, mem_ctx,
                          NULL, NULL);
