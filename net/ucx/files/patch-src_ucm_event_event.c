--- src/ucm/event/event.c.orig	2026-02-04 09:52:46 UTC
+++ src/ucm/event/event.c
@@ -36,6 +36,15 @@ KHASH_INIT(ucm_ptr_size, const void*, size_t, 1, ucm_p
 #define ucm_ptr_hash(_ptr)  kh_int64_hash_func((uintptr_t)(_ptr))
 KHASH_INIT(ucm_ptr_size, const void*, size_t, 1, ucm_ptr_hash, kh_int64_hash_equal)
 
+#if defined(__FreeBSD__)
+#ifndef MREMAP_FIXED
+#define MREMAP_FIXED 0
+#endif
+#ifndef MREMAP_MAYMOVE
+#define MREMAP_MAYMOVE 0
+#endif
+#endif
+
 static pthread_rwlock_t ucm_event_lock       = PTHREAD_RWLOCK_INITIALIZER;
 static ucs_init_once_t ucm_library_init_once = UCS_INIT_ONCE_INITIALIZER;
 static ucs_list_link_t ucm_event_handlers;
