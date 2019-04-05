--- content/public/app/v8_snapshot_overlay_manifest.cc.orig	2019-03-24 18:50:53.929211000 +0100
+++ content/public/app/v8_snapshot_overlay_manifest.cc	2019-03-24 18:51:09.015465000 +0100
@@ -15,7 +15,7 @@
 const service_manager::Manifest& GetV8SnapshotOverlayManifest() {
   static base::NoDestructor<service_manager::Manifest> manifest {
     service_manager::ManifestBuilder()
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
         .PreloadFile(kV8NativesDataDescriptor,
                      base::FilePath(FILE_PATH_LITERAL("natives_blob.bin")))
 #if defined(USE_V8_CONTEXT_SNAPSHOT)
