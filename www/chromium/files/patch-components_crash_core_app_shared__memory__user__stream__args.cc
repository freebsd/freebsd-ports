--- components/crash/core/app/shared_memory_user_stream_args.cc.orig	2026-10-18 13:29:39 UTC
+++ components/crash/core/app/shared_memory_user_stream_args.cc
@@ -7,7 +7,7 @@
 #include "build/build_config.h"
 
 static_assert(BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) ||
-                  BUILDFLAG(IS_CHROMEOS),
+                  BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD),
               "Unsupported platform.");
 
 #include <stdint.h>
