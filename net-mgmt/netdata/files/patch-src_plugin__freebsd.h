--- src/plugin_freebsd.h.orig	2017-01-22 19:49:22 UTC
+++ src/plugin_freebsd.h
@@ -6,9 +6,22 @@
 #define GETSYSCTL(name, var) getsysctl(name, &(var), sizeof(var))
 
 void *freebsd_main(void *ptr);
+extern int do_freebsd_sysctl(int update_every, usec_t dt);
 
-int getsysctl(const char *name, void *ptr, size_t len);
+static inline
+int getsysctl(const char *name, void *ptr, size_t len)
+{
+    size_t nlen = len;
 
-extern int do_freebsd_sysctl(int update_every, usec_t dt);
+    if (unlikely(sysctlbyname(name, ptr, &nlen, NULL, 0) == -1)) {
+        error("FREEBSD: sysctl(%s...) failed: %s", name, strerror(errno));
+        return 1;
+    }
+    if (unlikely(nlen != len)) {
+        error("FREEBSD: sysctl(%s...) expected %lu, got %lu", name, (unsigned long)len, (unsigned long)nlen);
+        return 1;
+    }
+    return 0;
+}
 
 #endif /* NETDATA_PLUGIN_FREEBSD_H */
