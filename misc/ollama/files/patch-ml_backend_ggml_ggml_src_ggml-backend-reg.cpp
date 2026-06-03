--- ml/backend/ggml/ggml/src/ggml-backend-reg.cpp.orig	1979-11-30 08:00:00 UTC
+++ ml/backend/ggml/ggml/src/ggml-backend-reg.cpp
@@ -545,11 +545,13 @@ static ggml_backend_reg_t ggml_backend_load_best(const
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
