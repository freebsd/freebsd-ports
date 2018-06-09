--- VTK/IO/EnSight/vtkEnSightGoldBinaryReader.cxx.orig	2018-05-30 20:37:02.610942000 +0700
+++ VTK/IO/EnSight/vtkEnSightGoldBinaryReader.cxx	2018-05-30 20:37:18.549087000 +0700
@@ -37,7 +37,7 @@
 #if defined(_WIN32)
 # define VTK_STAT_STRUCT struct _stat64
 # define VTK_STAT_FUNC _stat64
-#elif defined _DARWIN_FEATURE_64_BIT_INODE && !defined __FreeBSD__
+#elif defined _DARWIN_FEATURE_64_BIT_INODE || defined __FreeBSD__
 // FreeBSD and OSX now deprecate stat64
 # define VTK_STAT_STRUCT struct stat
 # define VTK_STAT_FUNC stat
