--- media/gpu/test/raw_video.cc.orig	2024-10-01 07:26:23 UTC
+++ media/gpu/test/raw_video.cc
@@ -60,7 +60,7 @@ std::unique_ptr<base::MemoryMappedFile> CreateMemoryMa
                              base::File::FLAG_READ | base::File::FLAG_WRITE
 // On Windows FLAG_CREATE_ALWAYS will require FLAG_WRITE, and FLAG_APPEND
 // must not be specified.
-#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
                              | base::File::FLAG_APPEND
 #endif  // BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
           ),
