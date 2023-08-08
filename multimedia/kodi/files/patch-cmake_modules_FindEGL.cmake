--- cmake/modules/FindEGL.cmake.orig	2023-01-16 15:23:00 UTC
+++ cmake/modules/FindEGL.cmake
@@ -36,11 +36,7 @@ if(EGL_FOUND)
   set(EGL_LIBRARIES ${EGL_LIBRARY})
   set(EGL_INCLUDE_DIRS ${EGL_INCLUDE_DIR})
   set(EGL_DEFINITIONS -DHAS_EGL=1)
-  include(CheckIncludeFiles)
-  check_include_files("EGL/egl.h;EGL/eglext.h;EGL/eglext_angle.h" HAVE_EGLEXTANGLE)
-  if(HAVE_EGLEXTANGLE)
-    list(APPEND EGL_DEFINITIONS "-DHAVE_EGLEXTANGLE=1")
-  endif()
+  list(APPEND EGL_DEFINITIONS "-DHAVE_EGLEXTANGLE=1")
 
   if(NOT TARGET EGL::EGL)
     add_library(EGL::EGL UNKNOWN IMPORTED)
