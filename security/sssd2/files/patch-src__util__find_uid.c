--- src/util/find_uid.c.orig	2024-05-16 11:35:27 UTC
+++ src/util/find_uid.c
@@ -36,6 +36,10 @@
 #include <ctype.h>
 #include <sys/time.h>
 #include <dhash.h>
+#ifdef __FreeBSD__
+#include <sys/sysctl.h>
+#include <sys/user.h>
+#endif
 
 #include "util/find_uid.h"
 #include "util/util.h"
@@ -325,9 +329,86 @@ done:
     return ret;
 }
 
-errno_t get_uid_table(TALLOC_CTX *mem_ctx, hash_table_t **table)
+#ifdef __FreeBSD__
+static errno_t get_active_uid_freebsd(hash_table_t *table, uid_t uid)
 {
+    struct kinfo_proc *kp;
+    hash_key_t key;
+    hash_value_t value;
+    size_t sz;
+    int err, mib[3];
+
+    mib[0] = CTL_KERN;
+    mib[1] = KERN_PROC;
+    mib[2] = KERN_PROC_PROC;
+
+    sz = 0;
+    err = sysctl(mib, 3, NULL, &sz, NULL, 0);
+    if (err) {
+        err = errno;
+        DEBUG(SSSDBG_CRIT_FAILURE, "sysctl failed.\n");
+        return err;
+    }
+    sz *= 2;
+
+    kp = talloc_size(NULL, sz);
+    if (kp == NULL) {
+        DEBUG(SSSDBG_CRIT_FAILURE, "talloc failed.\n");
+        return ENOMEM;
+    }
+
+    err = sysctl(mib, 3, kp, &sz, NULL, 0);
+    if (err) {
+        err = errno;
+        DEBUG(SSSDBG_CRIT_FAILURE, "sysctl failed.\n");
+        talloc_free(kp);
+        return err;
+    }
+
+    err = ENOENT;
+    for (size_t i = 0; i < sz / sizeof(struct kinfo_proc); i++) {
+        if (kp[i].ki_uid == 0) {
+            continue;
+        }
+
+        if (table != NULL) {
+            key.type = HASH_KEY_ULONG;
+            key.ul = (unsigned long) kp[i].ki_ruid;
+            value.type = HASH_VALUE_ULONG;
+            value.ul = (unsigned long) kp[i].ki_ruid;
+
+            err = hash_enter(table, &key, &value);
+            if (err != HASH_SUCCESS) {
+                DEBUG(SSSDBG_CRIT_FAILURE,
+                      "cannot add to table [%s]\n", hash_error_string(err));
+                err = ENOMEM;
+                break;
+            }
+        } else {
+            if (kp[i].ki_ruid == uid) {
+                err = EOK;
+                break;
+            }
+        }
+    }
+    talloc_free(kp);
+    return err;
+}
+#endif /* __FreeBSD__ */
+
+static errno_t get_active_uid(hash_table_t *table, uid_t uid)
+{
 #ifdef __linux__
+    return get_active_uid_linux(table, uid);
+#elif defined(__FreeBSD__)
+    return get_active_uid_freebsd(table, uid);
+#else
+    return ENOSYS;
+#endif
+}
+
+errno_t get_uid_table(TALLOC_CTX *mem_ctx, hash_table_t **table)
+{
     int ret;
 
     ret = hash_create_ex(0, table, 0, 0, 0, 0,
@@ -339,10 +420,7 @@ errno_t get_uid_table(TALLOC_CTX *mem_ctx, hash_table_
         return ENOMEM;
     }
 
-    return get_active_uid_linux(*table, 0);
-#else
-    return ENOSYS;
-#endif
+    return get_active_uid(*table, 0);
 }
 
 errno_t check_if_uid_is_active(uid_t uid, bool *result)
@@ -365,9 +443,9 @@ errno_t check_if_uid_is_active(uid_t uid, bool *result
     /* fall back to the old method */
 #endif
 
-    ret = get_active_uid_linux(NULL, uid);
+    ret = get_active_uid(NULL, uid);
     if (ret != EOK && ret != ENOENT) {
-        DEBUG(SSSDBG_CRIT_FAILURE, "get_active_uid_linux() failed.\n");
+        DEBUG(SSSDBG_CRIT_FAILURE, "get_active_uid() failed.\n");
         return ret;
     }
 
