--- net/http/http_auth_gssapi_posix.cc.orig	2013-09-02 22:50:25.000000000 +0300
+++ net/http/http_auth_gssapi_posix.cc	2013-09-02 22:52:13.000000000 +0300
@@ -430,8 +430,8 @@
     static const char* const kDefaultLibraryNames[] = {
 #if defined(OS_MACOSX)
       "libgssapi_krb5.dylib"  // MIT Kerberos
-#elif defined(OS_OPENBSD)
-      "libgssapi.so"          // Heimdal - OpenBSD
+#elif defined(OS_BSD)
+      "libgssapi.so"          // Heimdal - OpenBSD / FreeBSD
 #else
       "libgssapi_krb5.so.2",  // MIT Kerberos - FC, Suse10, Debian
       "libgssapi.so.4",       // Heimdal - Suse10, MDK
