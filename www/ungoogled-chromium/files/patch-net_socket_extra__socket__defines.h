--- net/socket/extra_socket_defines.h.orig	2026-10-31 12:09:36 UTC
+++ net/socket/extra_socket_defines.h
@@ -7,7 +7,7 @@
 
 #include "build/build_config.h"
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
 #include <netinet/in.h>
 #include <sys/socket.h>
 
