--- mojo/public/c/system/thunks.cc.orig	2019-01-09 11:00:07.794493000 +0100
+++ mojo/public/c/system/thunks.cc	2019-01-09 11:03:08.369317000 +0100
@@ -14,7 +14,7 @@
 #include "build/build_config.h"
 #include "mojo/public/c/system/core.h"
 
-#if defined(OS_CHROMEOS) || defined(OS_LINUX)
+#if defined(OS_CHROMEOS) || defined(OS_LINUX) || defined(OS_BSD)
 #include "base/environment.h"
 #include "base/files/file_path.h"
 #include "base/optional.h"
@@ -38,7 +38,7 @@
   typedef void (*MojoGetSystemThunksFunction)(MojoSystemThunks* thunks);
 
   CoreLibraryInitializer() {
-#if defined(OS_CHROMEOS) || defined(OS_LINUX)
+#if defined(OS_CHROMEOS) || defined(OS_LINUX) || defined(OS_BSD)
     auto environment = base::Environment::Create();
 
     base::FilePath library_path;
@@ -80,7 +80,7 @@
   ~CoreLibraryInitializer() = default;
 
  private:
-#if defined(OS_CHROMEOS) || defined(OS_LINUX)
+#if defined(OS_CHROMEOS) || defined(OS_LINUX) || defined(OS_BSD)
   base::Optional<base::ScopedNativeLibrary> library_;
 #endif
 
