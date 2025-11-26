--- far2l/src/mix/MountInfo.cpp.orig	2025-10-26 08:39:52 UTC
+++ far2l/src/mix/MountInfo.cpp
@@ -384,7 +384,7 @@ std::string MountInfo::GetFileSystem(const std::string
 	return out;
 }
 
-std::string MountInfo::GetFileSystemMountPoint(const wchar_t *lpwsz_path) const
+std::string MountInfo::GetFileSystemMountPoint(const wchar_t *lpwsz_path, bool want_device) const
 {
 	std::string out;
 	size_t longest_match = 0;
@@ -394,7 +394,7 @@ std::string MountInfo::GetFileSystemMountPoint(const w
 	for (const auto &it : *_mountpoints) {
 		if (it.path.size() > longest_match && StrStartsFrom(path, it.path.c_str())) {
 			longest_match = it.path.size();
-			out = it.path;
+			out = want_device ? it.device : it.path;
 		}
 	}
 	return out;
