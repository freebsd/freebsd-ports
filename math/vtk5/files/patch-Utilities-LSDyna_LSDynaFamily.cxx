--- Utilities/LSDyna/LSDynaFamily.cxx.orig	2012-09-07 10:04:57.000000000 +0200
+++ Utilities/LSDyna/LSDynaFamily.cxx	2012-09-07 10:07:21.000000000 +0200
@@ -33,7 +33,7 @@
 namespace
 {
 //Documentation on why the exemption
-#define USE_STAT_64 VTK_SIZEOF_ID_TYPE==8 && !defined _DARWIN_FEATURE_64_BIT_INODE
+#define USE_STAT_64 VTK_SIZEOF_ID_TYPE==8 && !defined _DARWIN_FEATURE_64_BIT_INODE && !defined __FreeBSD__
 //OSX uses stat instead of stat64
 #if (USE_STAT_64)
 //64bit
