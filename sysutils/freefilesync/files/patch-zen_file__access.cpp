--- ../../zen/file_access.cpp.orig	2016-01-11 12:13:10 UTC
+++ ../../zen/file_access.cpp
@@ -877,6 +877,11 @@ void setFileTimeRaw(const Zstring& fileP
     //https://sourceforge.net/p/freefilesync/discussion/open-discussion/thread/218564cf/
     newTimes[1] = modTime; //modification time
 
+#if defined(__FreeBSD__)
+#include <osreldate.h>
+#if __FreeBSD_version < 1002506 || (__FreeBSD_version >= 1100000 && __FreeBSD_version < 1100056)
+    throw ErrorLinuxFallbackToUtimes(L"");
+#else
     //=> using open()/futimens() for regular files and utimensat(AT_SYMLINK_NOFOLLOW) for symlinks is consistent with "cp" and "touch"!
     if (procSl == ProcSymlink::FOLLOW)
     {
@@ -898,6 +903,8 @@ void setFileTimeRaw(const Zstring& fileP
         if (::utimensat(AT_FDCWD, filePath.c_str(), newTimes, AT_SYMLINK_NOFOLLOW) != 0)
             THROW_LAST_FILE_ERROR(replaceCpy(_("Cannot write modification time of %x."), L"%x", fmtPath(filePath)), L"utimensat");
     }
+#endif
+#endif
 }
 
 
