--- src/media/gpu/test/raw_video.cc.orig	2026-10-18 18:43:23 UTC
+++ src/media/gpu/test/raw_video.cc
@@ -60,7 +60,7 @@ std::unique_ptr<base::MemoryMappedFile>
                              base::File::FLAG_READ | base::File::FLAG_WRITE
 // On Windows FLAG_CREATE_ALWAYS will require FLAG_WRITE, and FLAG_APPEND
 // must not be specified.
-#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
                              | base::File::FLAG_APPEND
 #endif  // BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
           ),
