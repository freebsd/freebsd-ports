--- far2l/src/mix/MountInfo.h.orig	2025-10-26 08:39:52 UTC
+++ far2l/src/mix/MountInfo.h
@@ -40,7 +40,7 @@ class MountInfo (public)
 
 	std::string GetFileSystem(const std::string &path) const;
 
-	std::string GetFileSystemMountPoint(const wchar_t *lpwsz_path) const;
+	std::string GetFileSystemMountPoint(const wchar_t *lpwsz_path, bool want_device = false) const;
 
 	/// Returns true if path fine to be used multi-threaded-ly
 	bool IsMultiThreadFriendly(const std::string &path) const;
