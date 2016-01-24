--- net/http/http_auth_gssapi_posix.cc.orig	2016-01-21 16:42:58.881942944 +0100
+++ net/http/http_auth_gssapi_posix.cc	2016-01-21 16:43:28.081940938 +0100
@@ -431,8 +431,8 @@
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
