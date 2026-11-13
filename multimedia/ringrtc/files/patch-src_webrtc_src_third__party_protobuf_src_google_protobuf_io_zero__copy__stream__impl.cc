--- src/webrtc/src/third_party/protobuf/src/google/protobuf/io/zero_copy_stream_impl.cc.orig	2026-11-06 09:52:35 UTC
+++ src/webrtc/src/third_party/protobuf/src/google/protobuf/io/zero_copy_stream_impl.cc
@@ -10,7 +10,7 @@
 //  Sanjay Ghemawat, Jeff Dean, and others.
 
 // We request posix_close if available. See the comment on "robust_close".
-#define _POSIX_C_SOURCE 202405L
+//#define _POSIX_C_SOURCE 202405L
 
 #ifndef _MSC_VER
 #include <fcntl.h>
