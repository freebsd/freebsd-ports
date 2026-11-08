--- plugins/obs-browser/obs-browser-plugin.cpp.orig	2026-10-29 21:06:38 UTC
+++ plugins/obs-browser/obs-browser-plugin.cpp
@@ -333,7 +333,7 @@ static void BrowserInit(void)
 	settings.multi_threaded_message_loop = false;
 #endif
 
-#if !defined(_WIN32) && !defined(__APPLE__)
+#if !defined(_WIN32) && !defined(__APPLE__) && !defined(__FreeBSD__)
 	// Override locale path from OBS binary path to plugin binary path
 	string locales = obs_get_module_binary_path(obs_current_module());
 	locales = locales.substr(0, locales.find_last_of('/') + 1);
@@ -716,7 +716,7 @@ static void check_hwaccel_support(void)
 		}
 	}
 }
-#elif __linux__
+#elif defined(__linux__) || defined(__FreeBSD__)
 static void check_hwaccel_support(void)
 {
 	/* NOTE: GL_VERSION returns a string that contains the driver vendor */
