--- net/http/http_auth_gssapi_posix.cc.orig	2019-03-11 22:01:01 UTC
+++ net/http/http_auth_gssapi_posix.cc
@@ -431,8 +431,9 @@ base::NativeLibrary GSSAPISharedLibrary::LoadSharedLib
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
