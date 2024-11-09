--- third_party/libc++/src/src/filesystem/filesystem_clock.cpp.orig	2024-11-04 08:56:03 UTC
+++ third_party/libc++/src/src/filesystem/filesystem_clock.cpp
@@ -30,7 +30,7 @@
 #endif
 
 #if defined(__APPLE__) || defined(__gnu_hurd__) || defined(__AMDGPU__) || defined(__NVPTX__) ||                        \
-    (defined(_POSIX_TIMERS) && _POSIX_TIMERS > 0)
+    (defined(_POSIX_TIMERS) && _POSIX_TIMERS > 0) || defined(__OpenBSD__) || defined(__FreeBSD__)
 #  define _LIBCPP_HAS_CLOCK_GETTIME
 #endif
 
