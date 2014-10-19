--- src/file/lib/baloo_xattr_p.h.orig	2014-08-21 13:16:09.854553785 +0200
+++ src/file/lib/baloo_xattr_p.h	2014-08-21 13:16:53.727550878 +0200
@@ -117,7 +117,7 @@
     #elif defined(Q_OS_MAC)
         return removexattr(encodedPath, attributeName, XATTR_NOFOLLOW );
     #elif defined(Q_OS_FREEBSD) || defined(Q_OS_NETBSD)
-        return removexattr (encodedPath, attributeName);
+        return extattr_delete_file (encodedPath, EXTATTR_NAMESPACE_USER, attributeName);
     #else
         return -1;
     #endif
