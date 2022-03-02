--- mojo/public/c/system/thunks.cc.orig	2022-02-28 16:54:41 UTC
+++ mojo/public/c/system/thunks.cc
@@ -19,7 +19,7 @@
 #include "mojo/public/c/system/core.h"
 #include "mojo/public/c/system/macros.h"
 
-#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 #include "base/environment.h"
 #include "base/files/file_path.h"
 #include "base/scoped_native_library.h"
@@ -67,7 +67,7 @@ class CoreLibraryInitializer {
   ~CoreLibraryInitializer() = default;
 
   MojoResult LoadLibrary(base::FilePath library_path) {
-#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
     if (library_ && library_->is_valid())
       return MOJO_RESULT_OK;
 
@@ -81,7 +81,7 @@ class CoreLibraryInitializer {
 
     if (library_path.empty()) {
       // Default to looking for the library in the current working directory.
-#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
       const base::FilePath::CharType kDefaultLibraryPathValue[] =
           FILE_PATH_LITERAL("./libmojo_core.so");
 #elif BUILDFLAG(IS_WIN)
@@ -131,7 +131,7 @@ class CoreLibraryInitializer {
   }
 
  private:
-#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   absl::optional<base::ScopedNativeLibrary> library_;
 #endif
 };
