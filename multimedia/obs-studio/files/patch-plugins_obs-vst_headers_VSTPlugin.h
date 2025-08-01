--- plugins/obs-vst/headers/VSTPlugin.h.orig	2025-08-01 04:32:45 UTC
+++ plugins/obs-vst/headers/VSTPlugin.h
@@ -73,7 +73,7 @@ class VSTPlugin : public QObject {
 	CFBundleRef bundle = NULL;
 #elif WIN32
 	HINSTANCE dllHandle = nullptr;
-#elif __linux__
+#elif __linux__ || __FreeBSD__
 	void *soHandle = nullptr;
 #endif
 
