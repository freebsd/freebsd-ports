--- net/http/http_auth_gssapi_posix.cc.orig	2015-07-15 16:30:05.000000000 -0400
+++ net/http/http_auth_gssapi_posix.cc	2015-07-22 07:50:14.149575000 -0400
@@ -432,8 +432,8 @@
 #if defined(OS_MACOSX)
       // This library is provided by Kerberos.framework.
       "libgssapi_krb5.dylib"
-#elif defined(OS_OPENBSD)
-      "libgssapi.so"          // Heimdal - OpenBSD
+#elif defined(OS_BSD)
+      "libgssapi.so"          // Heimdal - OpenBSD / FreeBSD
 #else
       "libgssapi_krb5.so.2",  // MIT Kerberos - FC, Suse10, Debian
       "libgssapi.so.4",       // Heimdal - Suse10, MDK
