--- core/cmake/BareosCheckIncludes.cmake	2020-02-03 01:03:16.451463000 -0500
+++ core/cmake/BareosCheckIncludes.cmake	2020-02-03 01:07:12.138547000 -0500
@@ -98,16 +98,20 @@
 check_include_files(sys/ea.h HAVE_SYS_EA_H)
 check_include_files(sys/proplist.h HAVE_SYS_PROPLIST_H)
 check_include_files(sys/xattr.h HAVE_SYS_XATTR_H)
-check_include_files(api/glfs.h HAVE_API_GLFS_H)
-
-check_include_files(cephfs/libcephfs.h HAVE_CEPHFS_LIBCEPHFS_H)
-check_include_files("sys/stat.h;cephfs/ceph_statx.h" HAVE_CEPHFS_CEPH_STATX_H)
-check_include_files(rados/librados.h HAVE_RADOS_LIBRADOS_H)
-check_include_files(radosstriper/libradosstriper.h
-                    HAVE_RADOSSTRIPER_LIBRADOSSTRIPER_H)
-
+if(gfapi)
+  check_include_files(glusterfs/api/glfs.h HAVE_API_GLFS_H)
 # CHECK_INCLUDE_FILES(glusterfs/glusterfs.h HAVE_GLUSTERFS_GLUSTERFS_H)
-check_include_files(glusterfs/api/glfs.h HAVE_GLUSTERFS_API_GLFS_H)
+  check_include_files(glusterfs/api/glfs.h HAVE_GLUSTERFS_API_GLFS_H)
+endif()
+if(cephfs)
+  check_include_files(cephfs/libcephfs.h HAVE_CEPHFS_LIBCEPHFS_H)
+  check_include_files("sys/stat.h;cephfs/ceph_statx.h" HAVE_CEPHFS_CEPH_STATX_H)
+endif()
+if(rados)
+  check_include_files(rados/librados.h HAVE_RADOS_LIBRADOS_H)
+  check_include_files(radosstriper/libradosstriper.h
+                      HAVE_RADOSSTRIPER_LIBRADOSSTRIPER_H)
+endif()
 
 check_include_files(elasto/data.h HAVE_ELASTO_DATA_H)
 check_include_files(elasto/file.h HAVE_ELASTO_FILE_H)
