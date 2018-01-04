--- Telegram/ThirdParty/libtgvoip/threading.h.orig	2017-07-06 17:16:18 UTC
+++ Telegram/ThirdParty/libtgvoip/threading.h
@@ -20,7 +20,7 @@ typedef pthread_cond_t tgvoip_lock_t;
 #define start_thread(ref, entry, arg) pthread_create(&ref, NULL, entry, arg)
 #define join_thread(thread) pthread_join(thread, NULL)
 #ifndef __APPLE__
-#define set_thread_name(thread, name) pthread_setname_np(thread, name)
+#define set_thread_name(thread, name)
 #else
 #define set_thread_name(thread, name)
 #endif
