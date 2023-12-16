--- components/services/screen_ai/screen_ai_library_wrapper.cc.orig	2023-11-22 14:00:11 UTC
+++ components/services/screen_ai/screen_ai_library_wrapper.cc
@@ -190,7 +190,7 @@ ScreenAILibraryWrapper::PerformOcr(const SkBitmap& ima
 
   // TODO(crbug.com/1443341): Remove this after fixing the crash issue on Linux
   // official.
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   free_library_allocated_char_array_(library_buffer.release());
 #endif
 
@@ -222,7 +222,7 @@ ScreenAILibraryWrapper::ExtractLayout(const SkBitmap& 
 
   // TODO(crbug.com/1443341): Remove this after fixing the crash issue on Linux
   // official.
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   free_library_allocated_char_array_(library_buffer.release());
 #endif
 
@@ -256,7 +256,7 @@ absl::optional<std::vector<int32_t>> ScreenAILibraryWr
 
   // TODO(crbug.com/1443341): Remove this after fixing the crash issue on Linux
   // official.
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   free_library_allocated_int32_array_(library_buffer.release());
 #endif
 
