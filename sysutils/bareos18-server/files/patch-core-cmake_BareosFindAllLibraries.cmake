--- core/cmake/BareosFindAllLibraries.cmake	2020-12-11 10:27:01.000000000 -0500
+++ core/cmake/BareosFindAllLibraries.cmake	2020-12-14 22:52:06.210892000 -0500
@@ -25,13 +25,15 @@
 
 
 if (NOT ${CMAKE_SYSTEM_NAME} MATCHES "Windows")
-   # make sure we get python 2 not 3
-   set(Python_ADDITIONAL_VERSIONS 2.5 2.6 2.7 2.8 2.9)
-   find_package(PythonInterp)
-   INCLUDE(FindPythonLibs)
+   if (python)
+     # make sure we get python 2 or 3
+     set(Python_ADDITIONAL_VERSIONS 3.5 3.6 3.7 3.8 2.7)
+     find_package(PythonInterp)
+     INCLUDE(FindPythonLibs)
 
-   if (${PYTHONLIBS_FOUND})
-      SET(HAVE_PYTHON 1)
+     if (${PYTHONLIBS_FOUND})
+        SET(HAVE_PYTHON 1)
+     endif()
    endif()
 
    INCLUDE(FindPostgreSQL)
@@ -52,13 +54,21 @@
 
 BareosFindLibraryAndHeaders("fastlz" "fastlzlib.h")
 BareosFindLibraryAndHeaders("jansson" "jansson.h")
-BareosFindLibraryAndHeaders("rados" "rados/librados.h")
-BareosFindLibraryAndHeaders("radosstriper" "radosstriper/libradosstriper.h")
-BareosFindLibraryAndHeaders("cephfs" "cephfs/libcephfs.h")
+if(rados)
+  BareosFindLibraryAndHeaders("rados" "rados/librados.h")
+  BareosFindLibraryAndHeaders("radosstriper" "radosstriper/libradosstriper.h")
+endif()
+if(cephfs)
+  BareosFindLibraryAndHeaders("cephfs" "cephfs/libcephfs.h")
+endif()
 BareosFindLibraryAndHeaders("pthread" "pthread.h")
 BareosFindLibraryAndHeaders("cap" "sys/capability.h")
-BareosFindLibraryAndHeaders("gfapi" "glusterfs/api/glfs.h")
-BareosFindLibraryAndHeaders("droplet" "droplet.h")
+if(gfapi)
+  BareosFindLibraryAndHeaders("gfapi" "glusterfs/api/glfs.h")
+endif()
+if(droplet)
+  BareosFindLibraryAndHeaders("droplet" "droplet.h")
+endif()
 
 BareosFindLibraryAndHeaders("pam" "security/pam_appl.h")
 
