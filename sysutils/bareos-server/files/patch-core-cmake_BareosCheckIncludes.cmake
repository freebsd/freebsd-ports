--- core/cmake/BareosCheckIncludes.cmake	2020-12-11 08:44:43.000000000 -0500
+++ core/cmake/BareosCheckIncludes.cmake	2020-12-14 19:30:00.380545000 -0500
@@ -100,21 +100,21 @@
 check_include_files(sys/xattr.h HAVE_SYS_XATTR_H)
 check_include_files(api/glfs.h HAVE_API_GLFS_H)
 
+if(cephfs)
 check_include_files(cephfs/libcephfs.h HAVE_CEPHFS_LIBCEPHFS_H)
+check_include_files("sys/stat.h;cephfs/ceph_ll_client.h" HAVE_CEPH_STATX)
+endif()
 
-include(CheckSymbolExists)
-include(CMakePushCheckState)
-cmake_push_check_state()
-set(CMAKE_REQUIRED_LIBRARIES cephfs)
-check_symbol_exists(ceph_statx "sys/stat.h;cephfs/libcephfs.h" HAVE_CEPH_STATX)
-cmake_pop_check_state()
-
+if(rados)
 check_include_files(rados/librados.h HAVE_RADOS_LIBRADOS_H)
 check_include_files(radosstriper/libradosstriper.h
                     HAVE_RADOSSTRIPER_LIBRADOSSTRIPER_H)
+endif()
 
 # CHECK_INCLUDE_FILES(glusterfs/glusterfs.h HAVE_GLUSTERFS_GLUSTERFS_H)
-check_include_files(glusterfs/api/glfs.h HAVE_GLUSTERFS_API_GLFS_H)
+if(gfapi)
+  check_include_files(glusterfs/api/glfs.h HAVE_GLUSTERFS_API_GLFS_H)
+endif()
 
 check_include_files(elasto/data.h HAVE_ELASTO_DATA_H)
 check_include_files(elasto/file.h HAVE_ELASTO_FILE_H)
