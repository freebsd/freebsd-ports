--- core/cmake/BareosCheckIncludes.cmake	2020-12-16 02:46:16.000000000 -0500
+++ core/cmake/BareosCheckIncludes.cmake	2020-12-23 22:25:00.323963000 -0500
@@ -60,19 +60,25 @@
 check_include_files(sys/proplist.h HAVE_SYS_PROPLIST_H)
 check_include_files(sys/xattr.h HAVE_SYS_XATTR_H)
 
-include(CheckSymbolExists)
-include(CMakePushCheckState)
-cmake_push_check_state()
-set(CMAKE_REQUIRED_LIBRARIES cephfs)
-check_symbol_exists(ceph_statx "sys/stat.h;cephfs/libcephfs.h" HAVE_CEPH_STATX)
-cmake_pop_check_state()
+if(cephfs)
+  include(CheckSymbolExists)
+  include(CMakePushCheckState)
+  cmake_push_check_state()
+  set(CMAKE_REQUIRED_LIBRARIES cephfs)
+  check_include_files("sys/stat.h;cephfs/ceph_ll_client.h" HAVE_CEPH_STATX)
+  cmake_pop_check_state()
+endif()
 
-check_include_files(rados/librados.h HAVE_RADOS_LIBRADOS_H)
-check_include_files(
-  radosstriper/libradosstriper.h HAVE_RADOSSTRIPER_LIBRADOSSTRIPER_H
-)
+if(rados)
+  check_include_files(rados/librados.h HAVE_RADOS_LIBRADOS_H)
+  check_include_files(
+    radosstriper/libradosstriper.h HAVE_RADOSSTRIPER_LIBRADOSSTRIPER_H
+  )
+endif()
 
-check_include_files(glusterfs/api/glfs.h HAVE_GLUSTERFS_API_GLFS_H)
+if(gfapi)
+  check_include_files(glusterfs/api/glfs.h HAVE_GLUSTERFS_API_GLFS_H)
+endif()
 
 check_include_files(sys/prctl.h HAVE_SYS_PRCTL_H)
 
