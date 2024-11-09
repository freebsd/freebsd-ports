--- third_party/libc++/src/src/chrono.cpp.orig	2024-11-04 08:56:03 UTC
+++ third_party/libc++/src/src/chrono.cpp
@@ -34,7 +34,7 @@
 // OpenBSD and GPU do not have a fully conformant suite of POSIX timers, but
 // it does have clock_gettime and CLOCK_MONOTONIC which is all we need.
 #if defined(__APPLE__) || defined(__gnu_hurd__) || defined(__OpenBSD__) || defined(__AMDGPU__) ||                      \
-    defined(__NVPTX__) || (defined(_POSIX_TIMERS) && _POSIX_TIMERS > 0)
+    defined(__NVPTX__) || (defined(_POSIX_TIMERS) && _POSIX_TIMERS > 0) || defined(__FreeBSD__)
 #  define _LIBCPP_HAS_CLOCK_GETTIME
 #endif
 
