--- src/plugin_freebsd.c.orig	2017-01-22 19:49:22 UTC
+++ src/plugin_freebsd.c
@@ -1,6 +1,6 @@
 #include "common.h"
 
-void *freebsd_main(void *ptr) {
+extern void *freebsd_main(void *ptr) {
     struct netdata_static_thread *static_thread = (struct netdata_static_thread *)ptr;
 
     info("FREEBSD Plugin thread created with task id %d", gettid());
@@ -63,17 +63,3 @@ void *freebsd_main(void *ptr) {
     return NULL;
 }
 
-int getsysctl(const char *name, void *ptr, size_t len)
-{
-    size_t nlen = len;
-
-    if (unlikely(sysctlbyname(name, ptr, &nlen, NULL, 0) == -1)) {
-        error("FREEBSD: sysctl(%s...) failed: %s", name, strerror(errno));
-        return 1;
-    }
-    if (unlikely(nlen != len)) {
-        error("FREEBSD: sysctl(%s...) expected %lu, got %lu", name, (unsigned long)len, (unsigned long)nlen);
-        return 1;
-    }
-    return 0;
-}
