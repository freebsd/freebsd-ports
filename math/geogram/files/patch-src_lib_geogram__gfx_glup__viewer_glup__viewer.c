--- src/lib/geogram_gfx/glup_viewer/glup_viewer.c.orig	2018-12-09 17:49:50 UTC
+++ src/lib/geogram_gfx/glup_viewer/glup_viewer.c
@@ -64,11 +64,11 @@
 #include <png/png.h>
 #endif
 
-#ifndef __APPLE__
+#if !defined(__APPLE__) && !defined(__FreeBSD__)
 #include <malloc.h>
 #endif
 
-#if defined(__APPLE__) || defined(__linux__) || defined(__EMSCRIPTEN__)
+#if defined(__APPLE__) || defined(__linux__) || defined(__FreeBSD__) || defined(__EMSCRIPTEN__)
 #include <unistd.h>
 static void glup_viewer_pause() {
     usleep(1000);
