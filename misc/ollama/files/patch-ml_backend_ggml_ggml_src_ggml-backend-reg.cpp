--- ml/backend/ggml/ggml/src/ggml-backend-reg.cpp.orig	2025-11-29 00:42:10.354754000 -0800
+++ ml/backend/ggml/ggml/src/ggml-backend-reg.cpp	2025-11-29 00:42:20.531699000 -0800
@@ -538,11 +538,13 @@
     std::vector<fs::path> search_paths;
     if (user_search_path == nullptr) {
 #ifdef GGML_BACKEND_DIR
+        // On FreeBSD, GGML_BACKEND_DIR is set to the correct library directory
         search_paths.push_back(fs::u8path(GGML_BACKEND_DIR));
-#endif
-        // default search paths: executable directory, current directory
+#else
+        // Fallback: search executable directory and current directory
         search_paths.push_back(get_executable_path());
         search_paths.push_back(fs::current_path());
+#endif
     } else {
         search_paths.push_back(fs::u8path(user_search_path));
     }
