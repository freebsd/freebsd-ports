--- core/cmake/BareosFindAllLibraries.cmake	2022-08-05 04:40:11.000000000 -0500
+++ core/cmake/BareosFindAllLibraries.cmake	2022-10-31 16:28:14.422391000 -0500
@@ -175,12 +175,18 @@
   )
 endif()
 
-bareosfindlibraryandheaders("rados" "rados/librados.h" "")
-bareosfindlibraryandheaders("radosstriper" "radosstriper/libradosstriper.h" "")
-bareosfindlibraryandheaders("cephfs" "cephfs/libcephfs.h" "")
+if(rados)
+  bareosfindlibraryandheaders("rados" "rados/librados.h" "")
+  bareosfindlibraryandheaders("radosstriper" "radosstriper/libradosstriper.h" "")
+endif()
+if(cephfs)
+  bareosfindlibraryandheaders("cephfs" "cephfs/libcephfs.h" "")
+endif()
 bareosfindlibraryandheaders("pthread" "pthread.h" "")
 bareosfindlibraryandheaders("cap" "sys/capability.h" "")
-bareosfindlibraryandheaders("gfapi" "glusterfs/api/glfs.h" "")
+if(gfapi)
+  bareosfindlibraryandheaders("gfapi" "glusterfs/api/glfs.h" "")
+endif()
 
 bareosfindlibraryandheaders("pam" "security/pam_appl.h" "")
 
