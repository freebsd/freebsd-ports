--- mozilla-release/ipc/chromium/src/third_party/libevent/evutil_rand.c.orig	2018-10-05 16:27:24 UTC
+++ mozilla-release/ipc/chromium/src/third_party/libevent/evutil_rand.c
@@ -192,7 +192,7 @@ evutil_secure_rng_get_bytes(void *buf, s
 	ev_arc4random_buf(buf, n);
 }
 
-#if !defined(__OpenBSD__) && !defined(ANDROID)
+#if !defined(__OpenBSD__) && !defined(__FreeBSD__) && !defined(ANDROID)
 void
 evutil_secure_rng_add_bytes(const char *buf, size_t n)
 {
