--- cmake/finders/FindCEF.cmake.orig	2026-08-14 22:07:04 UTC
+++ cmake/finders/FindCEF.cmake
@@ -154,7 +154,7 @@ elseif(CMAKE_HOST_SYSTEM_NAME STREQUAL D
     PATHS "${CEF_ROOT_DIR}/build/libcef_dll/Debug" "${CEF_ROOT_DIR}/build/libcef_dll_wrapper/Debug"
     DOC "Chromium Embedded Framework static library wrapper (debug)."
   )
-elseif(CMAKE_HOST_SYSTEM_NAME STREQUAL Linux)
+elseif(CMAKE_HOST_SYSTEM_NAME MATCHES "Linux|FreeBSD")
   find_library(
     CEF_LIBRARY_RELEASE
     NAMES libcef.so
