--- IO/EnSight/vtkEnSight6BinaryReader.cxx.orig	2017-11-21 07:34:56 UTC
+++ IO/EnSight/vtkEnSight6BinaryReader.cxx
@@ -36,8 +36,8 @@
 #if defined(_WIN32)
 # define VTK_STAT_STRUCT struct _stat64
 # define VTK_STAT_FUNC _stat64
-#elif defined _DARWIN_FEATURE_64_BIT_INODE && !defined __FreeBSD__
-// FreeBSD and OSX now deprecate stat64
+#elif defined _DARWIN_FEATURE_64_BIT_INODE || defined __FreeBSD__
+// FreeBSD and OSX use stat
 # define VTK_STAT_STRUCT struct stat
 # define VTK_STAT_FUNC stat
 #else
