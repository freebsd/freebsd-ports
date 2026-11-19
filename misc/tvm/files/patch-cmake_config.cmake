-- turn off libbacktrace

--- cmake/config.cmake.orig	2026-11-18 18:39:45 UTC
+++ cmake/config.cmake
@@ -273,11 +273,11 @@ set(USE_CCACHE AUTO)
 # - ON: Build from ffi/3rdparty/libbacktrace.
 # - OFF: Don't use libbacktrace.
 # - /path/to/libbacktrace: Looking for the libbacktrace header and static lib from a user-provided path. Report error if not found.
-set(TVM_FFI_USE_LIBBACKTRACE ON)
+set(TVM_FFI_USE_LIBBACKTRACE OFF)
 
 # Whether to install a signal handler to print a backtrace on segfault.
 # Need to have TVM_FFI_USE_LIBBACKTRACE enabled.
-set(TVM_FFI_BACKTRACE_ON_SEGFAULT ON)
+set(TVM_FFI_BACKTRACE_ON_SEGFAULT OFF)
 
 # Whether to use GoogleTest for C++ unit tests. When enabled, the generated
 # build file (e.g. Makefile) will have a target "cpptest".
