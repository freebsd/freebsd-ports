--- agent/kernel.c.orig	2023-08-15 20:32:01 UTC
+++ agent/kernel.c
@@ -252,7 +252,37 @@ free_kmem(void)
         kmem = -1;
     }
 }
+#elif defined(__FreeBSD__)
+kvm_t *kd;
 
+/**
+ * Initialize the libkvm descriptor. On FreeBSD we can use most of libkvm
+ * without requiring /dev/kmem access.  Only kvm_nlist() and kvm_read() need
+ * that, and we don't use them.
+ *
+ * @return TRUE upon success; FALSE upon failure.
+ */
+int
+init_kmem(const char *file)
+{
+    char err[4096];
+
+    kd = kvm_openfiles(NULL, "/dev/null", NULL, O_RDONLY, err);
+    if (!kd) {
+        snmp_log(LOG_CRIT, "init_kmem: kvm_openfiles failed: %s\n", err);
+        return FALSE;
+    }
+    return TRUE;
+}
+
+void
+free_kmem(void)
+{
+    if (kd != NULL) {
+        (void)kvm_close(kd);
+        kd = NULL;
+    }
+}
 #else
 int
 init_kmem(const char *file)
