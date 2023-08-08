--- core/cmake/BareosCheckIncludes.cmake	2023-03-24 08:05:20.000000000 -0500
+++ core/cmake/BareosCheckIncludes.cmake	2023-04-05 16:17:56.933566000 -0500
@@ -62,7 +62,9 @@
 
 include(CheckSymbolExists)
 
+if(gfapi)
 check_include_files(glusterfs/api/glfs.h HAVE_GLUSTERFS_API_GLFS_H)
+endif()
 
 check_include_files(sys/prctl.h HAVE_SYS_PRCTL_H)
 
