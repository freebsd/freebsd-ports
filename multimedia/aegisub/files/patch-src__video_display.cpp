--- src/video_display.cpp.orig
+++ src/video_display.cpp
@@ -69,6 +69,13 @@
 #include <GL/gl.h>
 #endif
 
+#ifdef _LIBCPP_VERSION
+#define TO_STRING(x) std::to_string(x)
+#else
+#include <boost/lexical_cast.hpp>
+#define TO_STRING(x) boost::lexical_cast<std::string>(x)
+#endif
+
 /// Attribute list for gl canvases; set the canvases to doublebuffered rgba with an 8 bit stencil buffer
 int attribList[] = { WX_GL_RGBA , WX_GL_DOUBLEBUFFER, WX_GL_STENCIL_SIZE, 8, 0 };
 
@@ -439,5 +446,5 @@
 }
 
 void VideoDisplay::OnSubtitlesSave() {
-	con->ass->SaveUIState("Video Zoom Percent", std::to_string(zoomValue));
+	con->ass->SaveUIState("Video Zoom Percent", TO_STRING(zoomValue));
 }
