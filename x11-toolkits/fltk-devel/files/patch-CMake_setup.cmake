--- CMake/setup.cmake.orig	2014-10-08 14:16:19.000000000 +0200
+++ CMake/setup.cmake	2014-10-08 14:16:59.000000000 +0200
@@ -58,8 +58,8 @@
    set(FLTK_CONFIG_PATH FLTK/.framework/Resources/CMake)
    set(FLTK_EXAMPLES_PATH share/fltk-examples)
 else()
-   set(FLTK_CONFIG_PATH lib/fltk)
-   set(FLTK_EXAMPLES_PATH share/fltk-examples)
+   set(FLTK_CONFIG_PATH lib/fltk-devel)
+   set(FLTK_EXAMPLES_PATH share/examples/fltk-devel)
 endif(WIN32 AND NOT CYGWIN)
 
 include(TestBigEndian)
