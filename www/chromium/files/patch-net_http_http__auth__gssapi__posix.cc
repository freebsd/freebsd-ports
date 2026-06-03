--- net/http/http_auth_gssapi_posix.cc.orig	2026-04-09 06:05:42 UTC
+++ net/http/http_auth_gssapi_posix.cc
@@ -364,7 +364,9 @@ base::NativeLibrary GSSAPISharedLibrary::LoadSharedLib
   } else {
 #if BUILDFLAG(IS_APPLE)
     library_names.emplace_back("/System/Library/Frameworks/GSS.framework/GSS");
-#elif BUILDFLAG(IS_OPENBSD)
+#elif BUILDFLAG(IS_BSD)
+    // MIT Kerberos - FreeBSD
+    library_names.emplace_back("libgssapi_krb5.so.2");
     // Heimdal - OpenBSD
     library_names.emplace_back("libgssapi.so");
 #else
