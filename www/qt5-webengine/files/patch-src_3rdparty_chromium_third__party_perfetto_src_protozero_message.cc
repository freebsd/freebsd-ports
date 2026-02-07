--- src/3rdparty/chromium/third_party/perfetto/src/protozero/message.cc.orig	2019-05-23 12:39:34 UTC
+++ src/3rdparty/chromium/third_party/perfetto/src/protozero/message.cc
@@ -21,12 +21,6 @@
 #include "perfetto/base/logging.h"
 #include "perfetto/protozero/message_handle.h"
 
-#if __BYTE_ORDER__ != __ORDER_LITTLE_ENDIAN__
-// The memcpy() for float and double below needs to be adjusted if we want to
-// support big endian CPUs. There doesn't seem to be a compelling need today.
-#error Unimplemented for big endian archs.
-#endif
-
 namespace protozero {
 
 // static
