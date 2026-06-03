--- remoting/base/username.h.orig	2026-04-09 06:05:42 UTC
+++ remoting/base/username.h
@@ -16,7 +16,7 @@ namespace remoting {
 // error or if not implemented.
 std::string GetUsername();
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // Returns the username that the network process is run as.
 base::cstring_view GetNetworkProcessUsername();
 #endif  // BUILDFLAG(IS_LINUX)
