--- src/ScreenCaptureReader.cpp.orig	2026-08-18 06:00:44 UTC
+++ src/ScreenCaptureReader.cpp
@@ -24,7 +24,7 @@
 #include <thread>
 #include <vector>
 
-#if defined(__linux__)
+#if defined(__unix__)
 	#include <dlfcn.h>
 #endif
 
@@ -47,7 +47,7 @@ using namespace openshot;
 
 using namespace openshot;
 
-#if defined(HAVE_WAYLAND_CAPTURE_PLUGIN) && defined(__linux__)
+#if defined(HAVE_WAYLAND_CAPTURE_PLUGIN) && defined(__unix__)
 namespace
 {
 	using WaylandBackendFactory = std::unique_ptr<ScreenCaptureReader::CaptureBackendReader> (*) (
@@ -81,7 +81,7 @@ namespace
 }
 #endif
 
-#if defined(__linux__)
+#if defined(__unix__)
 class ScreenCaptureReader::SystemAudioCapture
 {
 public:
@@ -620,13 +620,13 @@ ScreenCaptureReader::ScreenCaptureReader(const ScreenC
 	}
 	ValidateSettings();
 	PopulateInfo();
-#if defined(__linux__) || defined(_WIN32)
+#if defined(__unix__) || defined(_WIN32)
 	if (settings.capture_audio) {
 		system_audio = std::make_unique<SystemAudioCapture>(settings);
 	}
 #endif
 	if (UsesWaylandPortal()) {
-	#if defined(HAVE_WAYLAND_CAPTURE_PLUGIN) && defined(__linux__)
+	#if defined(HAVE_WAYLAND_CAPTURE_PLUGIN) && defined(__unix__)
 		std::string module_error;
 		backend_module = load_wayland_capture_backend(module_error);
 		if (!backend_module) {
@@ -663,7 +663,7 @@ ScreenCaptureReader::~ScreenCaptureReader()
 ScreenCaptureReader::~ScreenCaptureReader()
 {
 	Close();
-#if defined(__linux__)
+#if defined(__unix__)
 	backend_reader.reset();
 	if (backend_module) {
 		dlclose(backend_module);
@@ -680,7 +680,7 @@ bool ScreenCaptureReader::IsBackendSupported(ScreenCap
 
 bool ScreenCaptureReader::IsBackendSupported(ScreenCaptureBackend backend)
 {
-#if defined(__linux__)
+#if defined(__unix__)
 	if (backend == SCREEN_CAPTURE_X11 || backend == SCREEN_CAPTURE_AUTO) {
 		return true;
 	}
@@ -702,7 +702,7 @@ bool ScreenCaptureReader::IsSystemAudioSupported(Scree
 
 bool ScreenCaptureReader::IsSystemAudioSupported(ScreenCaptureBackend backend)
 {
-#if defined(__linux__)
+#if defined(__unix__)
 	if (backend == SCREEN_CAPTURE_AUTO) {
 		backend = DefaultBackend();
 	}
@@ -719,7 +719,7 @@ ScreenCaptureBackend ScreenCaptureReader::DefaultBacke
 
 ScreenCaptureBackend ScreenCaptureReader::DefaultBackend()
 {
-#if defined(__linux__)
+#if defined(__unix__)
 	const char* session = std::getenv("XDG_SESSION_TYPE");
 	if (session && std::string(session) == "wayland" && IsBackendSupported(SCREEN_CAPTURE_WAYLAND)) {
 		return SCREEN_CAPTURE_WAYLAND;
@@ -1297,7 +1297,7 @@ void ScreenCaptureReader::SetJsonValue(const Json::Val
 	}
 	ValidateSettings();
 	PopulateInfo();
-#if defined(__linux__) || defined(_WIN32)
+#if defined(__unix__) || defined(_WIN32)
 	system_audio.reset();
 	if (settings.capture_audio) {
 		system_audio = std::make_unique<SystemAudioCapture>(settings);
