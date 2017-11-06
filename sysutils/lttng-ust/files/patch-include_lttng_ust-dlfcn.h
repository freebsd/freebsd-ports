--- include/lttng/ust-dlfcn.h.orig	2016-11-29 01:46:24 UTC
+++ include/lttng/ust-dlfcn.h
@@ -27,6 +27,8 @@
  * SOFTWARE.
  */
 
+typedef long Lmid_t;
+
 #ifdef _DLFCN_H
 #error "Please include lttng/ust-dlfcn.h before dlfcn.h."
 #endif /* _DLFCN_H */
