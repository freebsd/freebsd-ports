--- encfs/encfs.cpp.orig	2016-09-18 20:16:04 UTC
+++ encfs/encfs.cpp
@@ -741,6 +741,6 @@ int encfs_removexattr(const char *path, 
                         bind(_do_removexattr, _1, _2, name));
 }
 
-}  // namespace encfs
-
 #endif  // HAVE_XATTR
+
+}  // namespace encfs
