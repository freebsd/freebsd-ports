--- mojo/public/c/system/thunks.cc.orig	2024-08-26 14:40:28 UTC
+++ mojo/public/c/system/thunks.cc
@@ -30,7 +30,7 @@
 #include "mojo/public/c/system/message_pipe.h"
 
 #if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || \
-    BUILDFLAG(IS_FUCHSIA)
+    BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
 #include "base/environment.h"
 #include "base/files/file_path.h"
 #include "base/scoped_native_library.h"
@@ -77,7 +77,7 @@ class CoreLibraryInitializer {
 
   MojoResult LoadLibrary(base::FilePath library_path) {
 #if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || \
-    BUILDFLAG(IS_FUCHSIA)
+    BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
     if (library_ && library_->is_valid())
       return MOJO_RESULT_OK;
 
@@ -91,7 +91,7 @@ class CoreLibraryInitializer {
 
     if (library_path.empty()) {
       // Default to looking for the library in the current working directory.
-#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
       const base::FilePath::CharType kDefaultLibraryPathValue[] =
           FILE_PATH_LITERAL("./libmojo_core.so");
 #elif BUILDFLAG(IS_FUCHSIA)
@@ -147,7 +147,7 @@ class CoreLibraryInitializer {
 
  private:
 #if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || \
-    BUILDFLAG(IS_FUCHSIA)
+    BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
   std::optional<base::ScopedNativeLibrary> library_;
 #endif
 };
