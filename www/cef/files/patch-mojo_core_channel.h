--- mojo/core/channel.h.orig	2026-07-01 06:24:19 UTC
+++ mojo/core/channel.h
@@ -169,7 +169,7 @@ class MOJO_SYSTEM_IMPL_EXPORT Channel
       } v2;
 
 #if BUILDFLAG(IS_ANDROID) || \
-    (BUILDFLAG(IS_LINUX) && defined(FUZZING_BUILD_MODE_UNSAFE_FOR_PRODUCTION))
+    ((BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && defined(FUZZING_BUILD_MODE_UNSAFE_FOR_PRODUCTION))
       // On Android for each pair of connected ipcz::Node instances both sides
       // of the connection run the same version of code. Restricting this
       // extension of IpczHeader to Android allows to iterate on the wire format
