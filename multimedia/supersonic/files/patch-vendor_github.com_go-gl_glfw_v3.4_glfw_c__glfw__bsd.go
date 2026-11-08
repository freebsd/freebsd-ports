--- vendor/github.com/go-gl/glfw/v3.4/glfw/c_glfw_bsd.go.orig	2026-08-21 05:47:56 UTC
+++ vendor/github.com/go-gl/glfw/v3.4/glfw/c_glfw_bsd.go
@@ -21,7 +21,6 @@ package glfw
 	#include "glfw/src/x11_window.c"
 	#include "glfw/src/glx_context.c"
 #endif
-#include "glfw/src/null_joystick.c"
 #include "glfw/src/posix_module.c"
 #include "glfw/src/posix_poll.c"
 #include "glfw/src/posix_time.c"
