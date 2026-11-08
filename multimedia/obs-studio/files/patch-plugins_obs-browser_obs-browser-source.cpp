--- plugins/obs-browser/obs-browser-source.cpp.orig	2026-10-29 21:06:38 UTC
+++ plugins/obs-browser/obs-browser-source.cpp
@@ -28,7 +28,7 @@
 #include <thread>
 #include <mutex>
 
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
 #include "linux-keyboard-helpers.hpp"
 #endif
 
@@ -323,7 +323,7 @@ void BrowserSource::SendKeyClick(const struct obs_key_
 	}
 
 	std::string text = event->text;
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
 	uint32_t native_vkey = KeyboardCodeFromXKeysym(event->native_vkey);
 	uint32_t modifiers = event->native_modifiers;
 #elif defined(_WIN32) || defined(__APPLE__)
@@ -357,7 +357,7 @@ void BrowserSource::SendKeyClick(const struct obs_key_
 			cefBrowser->GetHost()->SendKeyEvent(e);
 			if (!text.empty() && !key_up) {
 				e.type = KEYEVENT_CHAR;
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
 				e.windows_key_code = KeyboardCodeFromXKeysym(e.character);
 #elif defined(_WIN32)
 				e.windows_key_code = e.character;
