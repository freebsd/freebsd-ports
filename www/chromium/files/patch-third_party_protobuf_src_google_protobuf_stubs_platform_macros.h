--- third_party/protobuf/src/google/protobuf/stubs/platform_macros.h.orig	2019-01-10 00:35:34.145545000 +0100
+++ third_party/protobuf/src/google/protobuf/stubs/platform_macros.h	2019-01-10 00:35:53.135144000 +0100
@@ -117,7 +117,7 @@
 
 #undef GOOGLE_PROTOBUF_PLATFORM_ERROR
 
-#if defined(GOOGLE_PROTOBUF_OS_ANDROID) || defined(GOOGLE_PROTOBUF_OS_IPHONE) || defined(__OpenBSD__)
+#if defined(GOOGLE_PROTOBUF_OS_ANDROID) || defined(GOOGLE_PROTOBUF_OS_IPHONE) || defined(__FreeBSD__)
 // Android ndk does not support the __thread keyword very well yet. Here
 // we use pthread_key_create()/pthread_getspecific()/... methods for
 // TLS support on android.
