--- src/3rdparty/chromium/third_party/protobuf/src/google/protobuf/stubs/platform_macros.h.orig	2019-05-23 12:39:34 UTC
+++ src/3rdparty/chromium/third_party/protobuf/src/google/protobuf/stubs/platform_macros.h
@@ -117,7 +117,7 @@ GOOGLE_PROTOBUF_PLATFORM_ERROR
 
 #undef GOOGLE_PROTOBUF_PLATFORM_ERROR
 
-#if defined(GOOGLE_PROTOBUF_OS_ANDROID) || defined(GOOGLE_PROTOBUF_OS_IPHONE) || defined(__OpenBSD__)
+#if defined(GOOGLE_PROTOBUF_OS_ANDROID) || defined(GOOGLE_PROTOBUF_OS_IPHONE) || defined(__FreeBSD__)
 // Android ndk does not support the __thread keyword very well yet. Here
 // we use pthread_key_create()/pthread_getspecific()/... methods for
 // TLS support on android.
