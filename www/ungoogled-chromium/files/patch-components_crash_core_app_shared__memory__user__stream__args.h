--- components/crash/core/app/shared_memory_user_stream_args.h.orig	2026-10-31 12:09:36 UTC
+++ components/crash/core/app/shared_memory_user_stream_args.h
@@ -15,7 +15,7 @@
 #include "build/build_config.h"
 
 static_assert(BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) ||
-                  BUILDFLAG(IS_CHROMEOS),
+                  BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD),
               "Unsupported platform.");
 
 #include <set>
