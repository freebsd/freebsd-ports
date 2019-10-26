--- src/3rdparty/chromium/mojo/public/c/system/thunks.cc.orig	2019-05-23 12:39:34 UTC
+++ src/3rdparty/chromium/mojo/public/c/system/thunks.cc
@@ -16,7 +16,7 @@
 #include "build/build_config.h"
 #include "mojo/public/c/system/core.h"
 
-#if defined(OS_CHROMEOS) || defined(OS_LINUX) || defined(OS_WIN)
+#if defined(OS_CHROMEOS) || defined(OS_LINUX) || defined(OS_WIN) || defined(OS_BSD)
 #include "base/environment.h"
 #include "base/files/file_path.h"
 #include "base/optional.h"
@@ -28,7 +28,7 @@ namespace {
 
 typedef void (*MojoGetSystemThunksFunction)(MojoSystemThunks* thunks);
 
-#if defined(OS_CHROMEOS) || defined(OS_LINUX) || defined(OS_WIN)
+#if defined(OS_CHROMEOS) || defined(OS_LINUX) || defined(OS_WIN) || defined(OS_BSD)
 PROTECTED_MEMORY_SECTION
 base::ProtectedMemory<MojoGetSystemThunksFunction> g_get_thunks;
 #endif
@@ -65,7 +65,7 @@ namespace mojo {
 class CoreLibraryInitializer {
  public:
   CoreLibraryInitializer(const MojoInitializeOptions* options) {
-#if defined(OS_CHROMEOS) || defined(OS_LINUX) || defined(OS_WIN)
+#if defined(OS_CHROMEOS) || defined(OS_LINUX) || defined(OS_WIN) || defined(OS_BSD)
     bool application_provided_path = false;
     base::Optional<base::FilePath> library_path;
     if (options && options->struct_size >= sizeof(*options) &&
@@ -84,7 +84,7 @@ class CoreLibraryInitializer {
 
     if (!library_path) {
       // Default to looking for the library in the current working directory.
-#if defined(OS_CHROMEOS) || defined(OS_LINUX)
+#if defined(OS_CHROMEOS) || defined(OS_LINUX) || defined(OS_BSD)
       const base::FilePath::CharType kDefaultLibraryPathValue[] =
           FILE_PATH_LITERAL("./libmojo_core.so");
 #elif defined(OS_WIN)
@@ -147,7 +147,7 @@ class CoreLibraryInitializer {
   ~CoreLibraryInitializer() = default;
 
  private:
-#if defined(OS_CHROMEOS) || defined(OS_LINUX) || defined(OS_WIN)
+#if defined(OS_CHROMEOS) || defined(OS_LINUX) || defined(OS_WIN) || defined(OS_BSD)
   base::Optional<base::ScopedNativeLibrary> library_;
 #endif
 
