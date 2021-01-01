--- net/http/http_auth_gssapi_posix.cc.orig	2020-02-03 21:52:49 UTC
+++ net/http/http_auth_gssapi_posix.cc
@@ -367,8 +367,9 @@ base::NativeLibrary GSSAPISharedLibrary::LoadSharedLib
     static const char* const kDefaultLibraryNames[] = {
 #if defined(OS_MACOSX)
       "/System/Library/Frameworks/GSS.framework/GSS"
-#elif defined(OS_OPENBSD)
-      "libgssapi.so"          // Heimdal - OpenBSD
+#elif defined(OS_BSD)
+      "libgssapi_krb5.so.2",  // MIT Kerberos - FreeBSD
+      "libgssapi.so"          // Heimdal - OpenBSD, FreeBSD
 #else
       "libgssapi_krb5.so.2",  // MIT Kerberos - FC, Suse10, Debian
       "libgssapi.so.4",       // Heimdal - Suse10, MDK
