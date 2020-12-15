--- core/cmake/BareosCheckIncludes.cmake	2020-12-14 22:02:44.192311000 -0500
+++ core/cmake/BareosCheckIncludes.cmake	2020-12-14 22:06:25.053879000 -0500
@@ -103,20 +103,20 @@
 CHECK_INCLUDE_FILES(sys/xattr.h HAVE_SYS_XATTR_H)
 CHECK_INCLUDE_FILES(api/glfs.h HAVE_API_GLFS_H)
 
-CHECK_INCLUDE_FILES(cephfs/libcephfs.h HAVE_CEPHFS_LIBCEPHFS_H)
+if(cephfs)
+  CHECK_INCLUDE_FILES(cephfs/libcephfs.h HAVE_CEPHFS_LIBCEPHFS_H)
+  CHECK_INCLUDE_FILES("sys/stat.h;cephfs/ceph_ll_client.h" HAVE_CEPHFS_CEPH_STATX_H)
+endif()
 
-include(CheckSymbolExists)
-include(CMakePushCheckState)
-cmake_push_check_state()
-set(CMAKE_REQUIRED_LIBRARIES cephfs)
-check_symbol_exists(ceph_statx "sys/stat.h;cephfs/libcephfs.h" HAVE_CEPHFS_CEPH_STATX_H)
-cmake_pop_check_state()
+if(rados)
+  CHECK_INCLUDE_FILES(rados/librados.h HAVE_RADOS_LIBRADOS_H)
+  CHECK_INCLUDE_FILES(radosstriper/libradosstriper.h HAVE_RADOSSTRIPER_LIBRADOSSTRIPER_H)
+endif()
 
-CHECK_INCLUDE_FILES(rados/librados.h HAVE_RADOS_LIBRADOS_H)
-CHECK_INCLUDE_FILES(radosstriper/libradosstriper.h HAVE_RADOSSTRIPER_LIBRADOSSTRIPER_H)
-
 #CHECK_INCLUDE_FILES(glusterfs/glusterfs.h HAVE_GLUSTERFS_GLUSTERFS_H)
-CHECK_INCLUDE_FILES(glusterfs/api/glfs.h HAVE_GLUSTERFS_API_GLFS_H)
+if(gfapi)
+  CHECK_INCLUDE_FILES(glusterfs/api/glfs.h HAVE_GLUSTERFS_API_GLFS_H)
+endif()
 
 CHECK_INCLUDE_FILES(elasto/data.h HAVE_ELASTO_DATA_H)
 CHECK_INCLUDE_FILES(elasto/file.h HAVE_ELASTO_FILE_H)
