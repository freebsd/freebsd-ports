--- src/3rdparty/chromium/content/public/app/v8_snapshot_overlay_manifest.cc.orig	2019-05-23 12:39:34 UTC
+++ src/3rdparty/chromium/content/public/app/v8_snapshot_overlay_manifest.cc
@@ -15,7 +15,7 @@ namespace content {
 const service_manager::Manifest& GetV8SnapshotOverlayManifest() {
   static base::NoDestructor<service_manager::Manifest> manifest {
     service_manager::ManifestBuilder()
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
         .PreloadFile(kV8NativesDataDescriptor,
                      base::FilePath(FILE_PATH_LITERAL("natives_blob.bin")))
 #if defined(USE_V8_CONTEXT_SNAPSHOT)
