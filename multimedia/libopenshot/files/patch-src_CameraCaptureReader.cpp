--- src/CameraCaptureReader.cpp.orig	2026-08-18 06:00:44 UTC
+++ src/CameraCaptureReader.cpp
@@ -137,7 +137,7 @@ bool CameraCaptureReader::IsBackendSupported(CameraCap
 
 bool CameraCaptureReader::IsBackendSupported(CameraCaptureBackend backend)
 {
-#if defined(__linux__)
+#if defined(__unix__)
 	return backend == CAMERA_CAPTURE_V4L2 || backend == CAMERA_CAPTURE_AUTO;
 #elif defined(_WIN32)
 	return backend == CAMERA_CAPTURE_WINDOWS_DSHOW || backend == CAMERA_CAPTURE_AUTO;
@@ -151,7 +151,7 @@ CameraCaptureBackend CameraCaptureReader::DefaultBacke
 
 CameraCaptureBackend CameraCaptureReader::DefaultBackend()
 {
-#if defined(__linux__)
+#if defined(__unix__)
 	return CAMERA_CAPTURE_V4L2;
 #elif defined(_WIN32)
 	return CAMERA_CAPTURE_WINDOWS_DSHOW;
@@ -170,7 +170,7 @@ AudioDeviceList CameraCaptureReader::GetDeviceNames(Ca
 
 	AudioDeviceList devices;
 	const char* input_format_name = nullptr;
-#if defined(__linux__)
+#if defined(__unix__)
 	if (backend == CAMERA_CAPTURE_V4L2) {
 		input_format_name = "v4l2";
 	}
