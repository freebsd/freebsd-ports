--- core/cmake/BareosFindAllLibraries.cmake	2023-03-24 08:05:20.000000000 -0500
+++ core/cmake/BareosFindAllLibraries.cmake	2023-04-05 16:21:00.503424000 -0500
@@ -177,7 +177,9 @@
 
 bareosfindlibraryandheaders("pthread" "pthread.h" "")
 bareosfindlibraryandheaders("cap" "sys/capability.h" "")
+if(gfapi)
 bareosfindlibraryandheaders("gfapi" "glusterfs/api/glfs.h" "")
+endif()
 
 bareosfindlibraryandheaders("pam" "security/pam_appl.h" "")
 
