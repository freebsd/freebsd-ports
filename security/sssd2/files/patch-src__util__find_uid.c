--- src/util/find_uid.c.orig	2024-01-12 12:05:40 UTC
+++ src/util/find_uid.c
@@ -58,6 +58,97 @@ static void hash_talloc_free(void *ptr, void *pvt)
     talloc_free(ptr);
 }

+static int parse_procfs_linux(const char* buf, uid_t *uid, bool *is_systemd)
+{
+    char *p;
+    char *e;
+    char *endptr;
+    uint32_t num=0;
+    errno_t error=EOK;
+
+    /* Get uid */
+    p = strstr(buf, "\nUid:\t");
+    if (p != NULL) {
+        p += 6;
+        e = strchr(p,'\t');
+        if (e == NULL) {
+            DEBUG(SSSDBG_CRIT_FAILURE, "missing delimiter.\n");
+            return EINVAL;
+        } else {
+            *e = '\0';
+        }
+        num = (uint32_t) strtoint32(p, &endptr, 10);
+        error = errno;
+        if (error != 0) {
+            DEBUG(SSSDBG_CRIT_FAILURE,
+                  "strtol failed [%s].\n", strerror(error));
+            return error;
+        }
+        if (*endptr != '\0') {
+            DEBUG(SSSDBG_CRIT_FAILURE, "uid contains extra characters\n");
+            return EINVAL;
+        }
+
+    } else {
+        DEBUG(SSSDBG_CRIT_FAILURE, "format error\n");
+        return EINVAL;
+    }
+
+    /* Get process name. */
+    p = strstr(buf, "Name:\t");
+    if (p == NULL) {
+        DEBUG(SSSDBG_CRIT_FAILURE, "format error\n");
+        return EINVAL;
+    }
+    p += 6;
+    e = strchr(p,'\n');
+    if (e == NULL) {
+        DEBUG(SSSDBG_CRIT_FAILURE, "format error\n");
+        return EINVAL;
+    }
+    if (strncmp(p, "systemd", e-p) == 0 || strncmp(p, "(sd-pam)", e-p) == 0) {
+        *is_systemd = true;
+    } else {
+        *is_systemd = false;
+    }
+
+    *uid = num;
+
+    return error;
+}
+
+static int parse_procfs_freebsd(char* buf, uid_t *uid, bool *is_systemd)
+{
+    uint32_t field_idx=0;
+    errno_t error=EOK;
+    char** str = &buf, *token;
+
+    /* See man procfs
+       nextcloud 21186 4726 110 90383 ttyv0 ctty 1718001838,183475 11,76617 2,473238 select 1001 1001 1001,1001,0,5,44,920 -
+                                                                                            |uid|
+    */
+    while ((token = strsep(str, " ")) != NULL && field_idx < 11) {
+        field_idx++;
+    }
+
+    if (token == NULL || field_idx != 11) {
+        DEBUG(SSSDBG_CRIT_FAILURE, "format error %d %d\n", token, field_idx);
+        return EINVAL;
+    }
+
+    *uid = (uint32_t) strtoint32(token, NULL, 10);
+    error = errno;
+    if (error != 0) {
+        DEBUG(SSSDBG_CRIT_FAILURE,
+                "strtol failed [%s].\n", strerror(error));
+        return error;
+    }
+
+    *is_systemd = false;
+
+    return error;
+}
+
 static errno_t get_uid_from_pid(const pid_t pid, uid_t *uid, bool *is_systemd)
 {
     int ret;
@@ -65,10 +156,6 @@ static errno_t get_uid_from_pid(const pid_t pid, uid_t
     struct stat stat_buf;
     int fd;
     char buf[BUFSIZE];
-    char *p;
-    char *e;
-    char *endptr;
-    uint32_t num=0;
     errno_t error;

     ret = snprintf(path, PATHLEN, "/proc/%d/status", pid);
@@ -138,56 +225,14 @@ static errno_t get_uid_from_pid(const pid_t pid, uid_t
               "close failed [%d][%s].\n", error, strerror(error));
     }

-    /* Get uid */
-    p = strstr(buf, "\nUid:\t");
-    if (p != NULL) {
-        p += 6;
-        e = strchr(p,'\t');
-        if (e == NULL) {
-            DEBUG(SSSDBG_CRIT_FAILURE, "missing delimiter.\n");
-            return EINVAL;
-        } else {
-            *e = '\0';
-        }
-        num = (uint32_t) strtoint32(p, &endptr, 10);
-        error = errno;
-        if (error != 0) {
-            DEBUG(SSSDBG_CRIT_FAILURE,
-                  "strtol failed [%s].\n", strerror(error));
-            return error;
-        }
-        if (*endptr != '\0') {
-            DEBUG(SSSDBG_CRIT_FAILURE, "uid contains extra characters\n");
-            return EINVAL;
-        }
+#if defined(__linux__)
+    return parse_procfs_linux(buf, uid, is_systemd);
+#elif defined(__FreeBSD__)
+    return parse_procfs_freebsd(buf, uid, is_systemd);
+#else
+    return ENOSYS;
+#endif

-    } else {
-        DEBUG(SSSDBG_CRIT_FAILURE, "format error\n");
-        return EINVAL;
-    }
-
-    /* Get process name. */
-    p = strstr(buf, "Name:\t");
-    if (p == NULL) {
-        DEBUG(SSSDBG_CRIT_FAILURE, "format error\n");
-        return EINVAL;
-    }
-    p += 6;
-    e = strchr(p,'\n');
-    if (e == NULL) {
-        DEBUG(SSSDBG_CRIT_FAILURE, "format error\n");
-        return EINVAL;
-    }
-    if (strncmp(p, "systemd", e-p) == 0 || strncmp(p, "(sd-pam)", e-p) == 0) {
-        *is_systemd = true;
-    } else {
-        *is_systemd = false;
-    }
-
-    *uid = num;
-
-    return EOK;
-
 fail_fd:
     close(fd);
     return error;
@@ -212,7 +257,12 @@ static errno_t name_to_pid(const char *name, pid_t *pi
         return EINVAL;
     }

+    /* FreeBSD has /proc/0/... */
+#if defined(__FreeBSD__)
+    if (num < 0 || num >= INT_MAX) {
+#else
     if (num <= 0 || num >= INT_MAX) {
+#endif
         DEBUG(SSSDBG_CRIT_FAILURE, "pid out of range.\n");
         return ERANGE;
     }
@@ -228,7 +278,7 @@ static int only_numbers(char *p)
     return *p;
 }

-static errno_t get_active_uid_linux(hash_table_t *table, uid_t search_uid)
+static errno_t get_active_uid_procfs(hash_table_t *table, uid_t search_uid)
 {
     DIR *proc_dir = NULL;
     struct dirent *dirent;
@@ -327,7 +377,7 @@ errno_t get_uid_table(TALLOC_CTX *mem_ctx, hash_table_

 errno_t get_uid_table(TALLOC_CTX *mem_ctx, hash_table_t **table)
 {
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
     int ret;

     ret = hash_create_ex(0, table, 0, 0, 0, 0,
@@ -339,7 +389,7 @@ errno_t get_uid_table(TALLOC_CTX *mem_ctx, hash_table_
         return ENOMEM;
     }

-    return get_active_uid_linux(*table, 0);
+    return get_active_uid_procfs(*table, 0);
 #else
     return ENOSYS;
 #endif
@@ -365,9 +415,9 @@ errno_t check_if_uid_is_active(uid_t uid, bool *result
     /* fall back to the old method */
 #endif

-    ret = get_active_uid_linux(NULL, uid);
+    ret = get_active_uid_procfs(NULL, uid);
     if (ret != EOK && ret != ENOENT) {
-        DEBUG(SSSDBG_CRIT_FAILURE, "get_active_uid_linux() failed.\n");
+        DEBUG(SSSDBG_CRIT_FAILURE, "get_active_uid_procfs() failed.\n");
         return ret;
     }

