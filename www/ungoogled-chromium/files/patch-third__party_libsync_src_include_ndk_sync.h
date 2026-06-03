--- third_party/libsync/src/include/ndk/sync.h.orig	2026-05-09 18:09:27 UTC
+++ third_party/libsync/src/include/ndk/sync.h
@@ -28,6 +28,7 @@
 
 #include <stdint.h>
 
+#if 0 
 #include <linux/sync_file.h>
 
 __BEGIN_DECLS
@@ -93,7 +94,7 @@ void sync_file_info_free(struct sync_file_info *info);
 #endif // __ANDROID_API__ >= __ANDROID_API_O__
 
 __END_DECLS
-
+#endif
 #endif /* ANDROID_SYNC_H */
 
 /** @} */
