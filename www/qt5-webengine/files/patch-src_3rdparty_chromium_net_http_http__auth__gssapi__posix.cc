--- src/3rdparty/chromium/net/http/http_auth_gssapi_posix.cc.orig	2017-01-26 00:49:16 UTC
+++ src/3rdparty/chromium/net/http/http_auth_gssapi_posix.cc
@@ -431,8 +431,8 @@ base::NativeLibrary GSSAPISharedLibrary:
     static const char* const kDefaultLibraryNames[] = {
 #if defined(OS_MACOSX)
       "/System/Library/Frameworks/Kerberos.framework/Kerberos"
-#elif defined(OS_OPENBSD)
-      "libgssapi.so"          // Heimdal - OpenBSD
+#elif defined(OS_BSD)
+      "libgssapi.so"          // Heimdal - OpenBSD / FreeBSD
 #else
       "libgssapi_krb5.so.2",  // MIT Kerberos - FC, Suse10, Debian
       "libgssapi.so.4",       // Heimdal - Suse10, MDK
