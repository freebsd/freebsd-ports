--- include/asterisk/astobj2.h.orig	2014-07-18 17:55:38 UTC
+++ include/asterisk/astobj2.h
@@ -1546,6 +1546,8 @@ void ao2_container_unregister(const char
 #define ao2_link_flags(container, obj, flags)			__ao2_link((container), (obj), (flags))
 
 #endif
+static inline void ao2_cleanup_cleanup(void *obj)
+    { ao2_cleanup(*(void **)obj); }
 
 int __ao2_link_debug(struct ao2_container *c, void *obj_new, int flags, const char *tag, const char *file, int line, const char *func);
 int __ao2_link(struct ao2_container *c, void *obj_new, int flags);
