--- include/asterisk/astobj2.h.orig	2013-07-02 12:30:02.000000000 +0200
+++ include/asterisk/astobj2.h	2013-07-02 12:31:39.000000000 +0200
@@ -1472,5 +1472,7 @@
 #else
 #define ao2_cleanup(obj) __ao2_cleanup(obj)
 #endif
+static inline void ao2_cleanup_cleanup(void *obj)
+    { ao2_cleanup(*(void **)obj); }
 void ao2_iterator_cleanup(struct ao2_iterator *iter);
 #endif /* _ASTERISK_ASTOBJ2_H */
