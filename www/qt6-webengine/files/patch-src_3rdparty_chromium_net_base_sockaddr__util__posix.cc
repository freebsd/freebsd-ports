--- src/3rdparty/chromium/net/base/sockaddr_util_posix.cc.orig	2022-07-22 17:30:31 UTC
+++ src/3rdparty/chromium/net/base/sockaddr_util_posix.cc
@@ -41,7 +41,8 @@ bool FillUnixAddress(const std::string& socket_path,
     return true;
   }
 
-#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
+  // XXX ?
   // Convert the path given into abstract socket name. It must start with
   // the '\0' character, so we are adding it. |addr_len| must specify the
   // length of the structure exactly, as potentially the socket name may
