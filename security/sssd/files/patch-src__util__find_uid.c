From 0b1b319b34db96e2088c1f71d51ce95f819ccce8 Mon Sep 17 00:00:00 2001
From: Lukas Slebodnik <lukas.slebodnik@intrak.sk>
Date: Sat, 4 May 2013 16:08:12 +0200
Subject: [PATCH 24/34] patch-src__util__find_uid.c

---
 src/util/find_uid.c | 7 +++----
 1 file changed, 3 insertions(+), 4 deletions(-)

diff --git src/util/find_uid.c src/util/find_uid.c
index d34a4ab..b309b19 100644
--- src/util/find_uid.c
+++ src/util/find_uid.c
@@ -67,7 +67,7 @@ static errno_t get_uid_from_pid(const pid_t pid, uid_t *uid)
     uint32_t num=0;
     errno_t error;
 
-    ret = snprintf(path, PATHLEN, "/proc/%d/status", pid);
+    ret = snprintf(path, PATHLEN, "/compat/linux/proc/%d/status", pid);
     if (ret < 0) {
         DEBUG(1, ("snprintf failed"));
         return EINVAL;
@@ -206,7 +206,7 @@ static errno_t get_active_uid_linux(hash_table_t *table, uid_t search_uid)
     hash_key_t key;
     hash_value_t value;
 
-    proc_dir = opendir("/proc");
+    proc_dir = opendir("/compat/linux/proc");
     if (proc_dir == NULL) {
         ret = errno;
         DEBUG(1, ("Cannot open proc dir.\n"));
@@ -280,9 +280,8 @@ done:
 
 errno_t get_uid_table(TALLOC_CTX *mem_ctx, hash_table_t **table)
 {
-#ifdef __linux__
     int ret;
-
+#if 1
     ret = hash_create_ex(INITIAL_TABLE_SIZE, table, 0, 0, 0, 0,
                          hash_talloc, hash_talloc_free, mem_ctx,
                          NULL, NULL);
-- 
1.8.0

