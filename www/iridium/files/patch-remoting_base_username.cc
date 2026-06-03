--- remoting/base/username.cc.orig	2026-04-15 12:07:04 UTC
+++ remoting/base/username.cc
@@ -86,7 +86,7 @@ std::string GetUsername() {
 #endif  // BUILDFLAG(IS_POSIX) && !BUILDFLAG(IS_ANDROID)
 }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 
 base::cstring_view GetNetworkProcessUsername() {
   // Should be in sync with CRD_NETWORK_USER in
