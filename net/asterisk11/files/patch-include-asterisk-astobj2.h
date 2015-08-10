--- include/asterisk/astobj2.h.orig	2015-07-24 22:06:05 UTC
+++ include/asterisk/astobj2.h
@@ -1520,5 +1520,7 @@ void __ao2_cleanup_debug(void *obj, cons
 #else
 #define ao2_cleanup(obj) __ao2_cleanup(obj)
 #endif
+static inline void ao2_cleanup_cleanup(void *obj)
+    { ao2_cleanup(*(void **)obj); }
 void ao2_iterator_cleanup(struct ao2_iterator *iter);
 #endif /* _ASTERISK_ASTOBJ2_H */
