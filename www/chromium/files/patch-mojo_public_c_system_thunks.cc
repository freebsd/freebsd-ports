--- mojo/public/c/system/thunks.cc.orig	2022-02-07 13:39:41 UTC
+++ mojo/public/c/system/thunks.cc
@@ -19,7 +19,7 @@
 #include "mojo/public/c/system/core.h"
 #include "mojo/public/c/system/macros.h"
 
-#if defined(OS_CHROMEOS) || defined(OS_LINUX) || defined(OS_WIN)
+#if defined(OS_CHROMEOS) || defined(OS_LINUX) || defined(OS_WIN) || defined(OS_BSD)
 #include "base/environment.h"
 #include "base/files/file_path.h"
 #include "base/scoped_native_library.h"
@@ -67,7 +67,7 @@ class CoreLibraryInitializer {
   ~CoreLibraryInitializer() = default;
 
   MojoResult LoadLibrary(base::FilePath library_path) {
-#if defined(OS_CHROMEOS) || defined(OS_LINUX) || defined(OS_WIN)
+#if defined(OS_CHROMEOS) || defined(OS_LINUX) || defined(OS_WIN) || defined(OS_BSD)
     if (library_ && library_->is_valid())
       return MOJO_RESULT_OK;
 
@@ -81,7 +81,7 @@ class CoreLibraryInitializer {
 
     if (library_path.empty()) {
       // Default to looking for the library in the current working directory.
-#if defined(OS_CHROMEOS) || defined(OS_LINUX)
+#if defined(OS_CHROMEOS) || defined(OS_LINUX) || defined(OS_BSD)
       const base::FilePath::CharType kDefaultLibraryPathValue[] =
           FILE_PATH_LITERAL("./libmojo_core.so");
 #elif defined(OS_WIN)
@@ -131,7 +131,7 @@ class CoreLibraryInitializer {
   }
 
  private:
-#if defined(OS_CHROMEOS) || defined(OS_LINUX) || defined(OS_WIN)
+#if defined(OS_CHROMEOS) || defined(OS_LINUX) || defined(OS_WIN) || defined(OS_BSD)
   absl::optional<base::ScopedNativeLibrary> library_;
 #endif
 };
