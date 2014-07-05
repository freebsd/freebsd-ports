--- src/video_out_gl.h.orig
+++ src/video_out_gl.h
@@ -23,6 +23,13 @@
 
 #include <vector>
 
+#ifdef _LIBCPP_VERSION
+#define TO_STRING(x) std::to_string(x)
+#else
+#include <boost/lexical_cast.hpp>
+#define TO_STRING(x) boost::lexical_cast<std::string>(x)
+#endif
+
 struct VideoFrame;
 
 /// @class VideoOutGL
@@ -92,7 +99,7 @@
 class VideoOutRenderException : public VideoOutException {
 public:
 	VideoOutRenderException(const char *func, int err)
-	: VideoOutException(std::string(func) + " failed with error code " + std::to_string(err))
+	: VideoOutException(std::string(func) + " failed with error code " + TO_STRING(err))
 	{ }
 	const char * GetName() const override { return "videoout/opengl/render"; }
 	Exception * Copy() const override { return new VideoOutRenderException(*this); }
@@ -103,7 +110,7 @@
 class VideoOutInitException : public VideoOutException {
 public:
 	VideoOutInitException(const char *func, int err)
-	: VideoOutException(std::string(func) + " failed with error code " + std::to_string(err))
+	: VideoOutException(std::string(func) + " failed with error code " + TO_STRING(err))
 	{ }
 	VideoOutInitException(const char *err) : VideoOutException(err) { }
 	const char * GetName() const override { return "videoout/opengl/init"; }
