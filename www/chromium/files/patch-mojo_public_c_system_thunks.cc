--- mojo/public/c/system/thunks.cc.orig	2019-01-08 19:19:50.188491000 +0100
+++ mojo/public/c/system/thunks.cc	2019-01-08 19:21:20.891924000 +0100
@@ -16,7 +16,7 @@
 #include "build/build_config.h"
 #include "mojo/public/c/system/core.h"
 
-#if defined(OS_CHROMEOS) || defined(OS_LINUX) || defined(OS_WIN)
+#if defined(OS_CHROMEOS) || defined(OS_LINUX) || defined(OS_WIN) || defined(OS_BSD)
 #include "base/environment.h"
 #include "base/files/file_path.h"
 #include "base/optional.h"
@@ -28,7 +28,7 @@
 
 typedef void (*MojoGetSystemThunksFunction)(MojoSystemThunks* thunks);
 
-#if defined(OS_CHROMEOS) || defined(OS_LINUX) || defined(OS_WIN)
+#if defined(OS_CHROMEOS) || defined(OS_LINUX) || defined(OS_WIN) || defined(OS_BSD)
 PROTECTED_MEMORY_SECTION
 base::ProtectedMemory<MojoGetSystemThunksFunction> g_get_thunks;
 #endif
@@ -63,7 +63,7 @@
 class CoreLibraryInitializer {
  public:
   CoreLibraryInitializer(const MojoInitializeOptions* options) {
-#if defined(OS_CHROMEOS) || defined(OS_LINUX) || defined(OS_WIN)
+#if defined(OS_CHROMEOS) || defined(OS_LINUX) || defined(OS_WIN) || defined(OS_BSD)
     bool application_provided_path = false;
     base::Optional<base::FilePath> library_path;
     if (options && options->struct_size >= sizeof(*options) &&
@@ -82,7 +82,7 @@
 
     if (!library_path) {
       // Default to looking for the library in the current working directory.
-#if defined(OS_CHROMEOS) || defined(OS_LINUX)
+#if defined(OS_CHROMEOS) || defined(OS_LINUX) || defined(OS_BSD)
       const base::FilePath::CharType kDefaultLibraryPathValue[] =
           FILE_PATH_LITERAL("./libmojo_core.so");
 #elif defined(OS_WIN)
@@ -132,7 +132,7 @@
   ~CoreLibraryInitializer() = default;
 
  private:
-#if defined(OS_CHROMEOS) || defined(OS_LINUX) || defined(OS_WIN)
+#if defined(OS_CHROMEOS) || defined(OS_LINUX) || defined(OS_WIN) || defined(OS_BSD)
   base::Optional<base::ScopedNativeLibrary> library_;
 #endif
 
