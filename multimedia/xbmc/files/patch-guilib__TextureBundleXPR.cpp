--- ./guilib/TextureBundleXPR.cpp.orig	2010-05-13 09:06:42.000000000 +0200
+++ ./guilib/TextureBundleXPR.cpp	2010-12-01 12:17:34.307278095 +0100
@@ -285,7 +285,7 @@
     GlobalMemoryStatus(&stat);
     CLog::Log(LOGERROR, "Out of memory loading texture: %s (need %lu bytes, have %lu bytes)", name.c_str(),
               file->second.UnpackedSize + file->second.PackedSize, stat.dwAvailPhys);
-#elif defined(__APPLE__)
+#elif defined(__APPLE__) || defined(__FreeBSD__)
     CLog::Log(LOGERROR, "Out of memory loading texture: %s (need %d bytes)", name.c_str(),
               file->second.UnpackedSize + file->second.PackedSize);
 #else
