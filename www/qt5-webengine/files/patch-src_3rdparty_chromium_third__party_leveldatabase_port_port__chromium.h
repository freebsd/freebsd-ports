--- src/3rdparty/chromium/third_party/leveldatabase/port/port_chromium.h.orig	2019-05-23 12:39:34 UTC
+++ src/3rdparty/chromium/third_party/leveldatabase/port/port_chromium.h
@@ -23,8 +23,11 @@
 namespace leveldb {
 namespace port {
 
-// Chromium only supports little endian.
+#if ARCH_CPU_LITTLE_ENDIAN
 static const bool kLittleEndian = true;
+#else
+static const bool kLittleEndian = false;
+#endif
 
 class LOCKABLE Mutex {
  public:
