--- core/cmake/BareosCheckIncludes.cmake.orig	2024-12-16 09:10:50.000000000 -0800
+++ core/cmake/BareosCheckIncludes.cmake	2024-12-22 19:21:38.094235000 -0800
@@ -62,7 +62,9 @@
 
   include(CheckSymbolExists)
 
+if(gfapi)
   check_include_files(glusterfs/api/glfs.h HAVE_GLUSTERFS_API_GLFS_H)
+endif()
 
   check_include_files(sys/prctl.h HAVE_SYS_PRCTL_H)
 
