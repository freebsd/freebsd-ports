--- src/core/display.h.orig	2016-12-07 11:54:56 UTC
+++ src/core/display.h
@@ -59,7 +59,6 @@ class SDLAppDisplay {
 
     bool enable_alpha;
     bool resizable;
-    bool fullscreen;
     bool frameless;
     bool vsync;
 
@@ -71,6 +70,7 @@ class SDLAppDisplay {
     void setupExtensions();
 public:
     int width, height;
+    bool fullscreen;
     int desktop_width, desktop_height;
     int windowed_width, windowed_height;
 
