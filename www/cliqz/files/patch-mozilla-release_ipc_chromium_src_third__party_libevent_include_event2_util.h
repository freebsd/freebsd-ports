--- mozilla-release/ipc/chromium/src/third_party/libevent/include/event2/util.h.orig	2018-11-12 18:39:53 UTC
+++ mozilla-release/ipc/chromium/src/third_party/libevent/include/event2/util.h
@@ -842,7 +842,7 @@ int evutil_secure_rng_init(void);
 EVENT2_EXPORT_SYMBOL
 int evutil_secure_rng_set_urandom_device_file(char *fname);
 
-#if !defined(__OpenBSD__) && !defined(ANDROID)
+#if !defined(__OpenBSD__) && !defined(__FreeBSD__) && !defined(ANDROID)
 /** Seed the random number generator with extra random bytes.
 
     You should almost never need to call this function; it should be
