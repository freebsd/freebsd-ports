--- src/3rdparty/chromium/net/http/http_auth_gssapi_posix.cc.orig	2018-11-13 18:25:11 UTC
+++ src/3rdparty/chromium/net/http/http_auth_gssapi_posix.cc
@@ -431,8 +431,9 @@ base::NativeLibrary GSSAPISharedLibrary::LoadSharedLib
     static const char* const kDefaultLibraryNames[] = {
 #if defined(OS_MACOSX)
       "/System/Library/Frameworks/GSS.framework/GSS"
-#elif defined(OS_OPENBSD)
-      "libgssapi.so"          // Heimdal - OpenBSD
+#elif defined(OS_BSD)
+      "libgssapi.so"          // Heimdal - OpenBSD / FreeBSD
+      "libgssapi_krb5.so.2",  // MIT Kerberos - FreeBSD
 #else
       "libgssapi_krb5.so.2",  // MIT Kerberos - FC, Suse10, Debian
       "libgssapi.so.4",       // Heimdal - Suse10, MDK
