--- src/3rdparty/chromium/net/http/http_auth_gssapi_posix.cc.orig	2022-09-26 10:05:50 UTC
+++ src/3rdparty/chromium/net/http/http_auth_gssapi_posix.cc
@@ -369,8 +369,9 @@ base::NativeLibrary GSSAPISharedLibrary::LoadSharedLib
     static const char* const kDefaultLibraryNames[] = {
 #if BUILDFLAG(IS_APPLE)
       "/System/Library/Frameworks/GSS.framework/GSS"
-#elif BUILDFLAG(IS_OPENBSD)
-      "libgssapi.so"  // Heimdal - OpenBSD
+#elif BUILDFLAG(IS_BSD)
+      "libgssapi_krb5.so.2",  // MIT Kerberos - FreeBSD
+      "libgssapi.so"          // Heimdal - OpenBSD, FreeBSD
 #else
       "libgssapi_krb5.so.2",  // MIT Kerberos - FC, Suse10, Debian
       "libgssapi.so.4",       // Heimdal - Suse10, MDK
