--- IO/LSDyna/private/LSDynaFamily.cxx.orig	2013-06-25 14:13:58.000000000 +0200
+++ IO/LSDyna/private/LSDynaFamily.cxx	2013-06-25 14:17:08.000000000 +0200
@@ -33,7 +33,7 @@
 namespace
 {
 //Documentation on why the exemption
-#define USE_STAT_64 VTK_SIZEOF_ID_TYPE==8 && !defined _DARWIN_FEATURE_64_BIT_INODE
+#define USE_STAT_64 VTK_SIZEOF_ID_TYPE==8 && !defined _DARWIN_FEATURE_64_BIT_INODE && !defined __FreeBSD__
 //OSX uses stat instead of stat64
 #if (USE_STAT_64)
 //64bit
