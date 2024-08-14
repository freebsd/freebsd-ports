--- net/base/sockaddr_util_posix.cc.orig	2024-08-01 05:47:53 UTC
+++ net/base/sockaddr_util_posix.cc
@@ -46,7 +46,8 @@ bool FillUnixAddress(const std::string& socket_path,
     return true;
   }
 
-#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
+  // XXX ?
   // Convert the path given into abstract socket name. It must start with
   // the '\0' character, so we are adding it. |addr_len| must specify the
   // length of the structure exactly, as potentially the socket name may
