--- src/3rdparty/chromium/third_party/flatbuffers/src/include/flatbuffers/base.h.orig	2019-05-23 12:39:34 UTC
+++ src/3rdparty/chromium/third_party/flatbuffers/src/include/flatbuffers/base.h
@@ -220,18 +220,15 @@ template<typename T> T EndianSwap(T t) {
   if (sizeof(T) == 1) {   // Compile-time if-then's.
     return t;
   } else if (sizeof(T) == 2) {
-    union { T t; uint16_t i; } u;
-    u.t = t;
+    union U { T t; uint16_t i; U(const T& t_) : t(t_) {}} u(t);
     u.i = FLATBUFFERS_BYTESWAP16(u.i);
     return u.t;
   } else if (sizeof(T) == 4) {
-    union { T t; uint32_t i; } u;
-    u.t = t;
+    union U { T t; uint32_t i; U(const T& t_) : t(t_) {}} u(t);
     u.i = FLATBUFFERS_BYTESWAP32(u.i);
     return u.t;
   } else if (sizeof(T) == 8) {
-    union { T t; uint64_t i; } u;
-    u.t = t;
+    union U { T t; uint64_t i; U(const T& t_) : t(t_) {}} u(t);
     u.i = FLATBUFFERS_BYTESWAP64(u.i);
     return u.t;
   } else {
