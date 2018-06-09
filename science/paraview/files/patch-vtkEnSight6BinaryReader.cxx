--- VTK/IO/EnSight/vtkEnSight6BinaryReader.cxx.orig	2018-05-30 20:27:53.507473000 +0700
+++ VTK/IO/EnSight/vtkEnSight6BinaryReader.cxx	2018-05-30 20:34:17.396774000 +0700
@@ -36,7 +36,7 @@
 #if defined(_WIN32)
 # define VTK_STAT_STRUCT struct _stat64
 # define VTK_STAT_FUNC _stat64
-#elif defined _DARWIN_FEATURE_64_BIT_INODE && !defined __FreeBSD__
+#elif defined _DARWIN_FEATURE_64_BIT_INODE || defined __FreeBSD__
 // FreeBSD and OSX now deprecate stat64
 # define VTK_STAT_STRUCT struct stat
 # define VTK_STAT_FUNC stat
