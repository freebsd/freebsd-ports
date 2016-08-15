--- third_party/protobuf/src/google/protobuf/stubs/platform_macros.h.orig	2016-08-04 11:23:35.218593000 -0400
+++ third_party/protobuf/src/google/protobuf/stubs/platform_macros.h	2016-08-04 11:24:32.984837000 -0400
@@ -111,7 +111,7 @@
 
 #undef GOOGLE_PROTOBUF_PLATFORM_ERROR
 
-#if defined(GOOGLE_PROTOBUF_OS_ANDROID) || defined(GOOGLE_PROTOBUF_OS_APPLE)
+#if defined(GOOGLE_PROTOBUF_OS_ANDROID) || defined(GOOGLE_PROTOBUF_OS_APPLE) || defined(__OpenBSD__) || defined(__FreeBSD__)
 // Android ndk does not support the __thread keyword very well yet. Here
 // we use pthread_key_create()/pthread_getspecific()/... methods for
 // TLS support on android.
