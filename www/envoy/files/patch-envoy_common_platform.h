--- envoy/common/platform.h.orig	2023-04-27 12:00:08 UTC
+++ envoy/common/platform.h
@@ -208,7 +208,7 @@ constexpr bool win32SupportsOriginalDestination() {
 
 #undef TRUE
 #else
-#include <endian.h>
+#include <sys/endian.h>
 #endif
 
 #if defined(__linux__)
@@ -288,7 +288,7 @@ constexpr absl::string_view null_device_path{"/dev/nul
 // Therefore, we decided to remove the Android check introduced here in
 // https://github.com/envoyproxy/envoy/pull/10120. If someone out there encounters problems with
 // this please bring up in Envoy's slack channel #envoy-udp-quic-dev.
-#if defined(__linux__) || defined(__EMSCRIPTEN__)
+#if defined(__linux__) || defined(__EMSCRIPTEN__) || defined(__FreeBSD__)
 #define ENVOY_MMSG_MORE 1
 #else
 #define ENVOY_MMSG_MORE 0
