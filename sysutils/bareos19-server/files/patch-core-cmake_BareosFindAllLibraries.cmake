--- core/cmake/BareosFindAllLibraries.cmake	2020-01-31 11:21:18.000000000 -0500
+++ core/cmake/BareosFindAllLibraries.cmake	2020-02-03 00:55:59.098603000 -0500
@@ -23,20 +23,22 @@
 endif()
 
 if(NOT ${CMAKE_SYSTEM_NAME} MATCHES "Windows")
-  # make sure we get python 2 not 3
-  set(
-    Python_ADDITIONAL_VERSIONS
-    2.5
-    2.6
-    2.7
-    2.8
-    2.9
-  )
-  find_package(PythonInterp)
-  include(FindPythonLibs)
+  if (python)
+    # make sure we get python 2 not 3
+    set(
+      Python_ADDITIONAL_VERSIONS
+      3.5
+      3.6
+      3.7
+      3.8
+      2.9
+    )
+    find_package(PythonInterp)
+    include(FindPythonLibs)
 
-  if(${PYTHONLIBS_FOUND})
-    set(HAVE_PYTHON 1)
+    if(${PYTHONLIBS_FOUND})
+      set(HAVE_PYTHON 1)
+    endif()
   endif()
 
   include(FindPostgreSQL)
@@ -56,13 +58,22 @@
 include(BareosFindLibraryAndHeaders)
 
 bareosfindlibraryandheaders("jansson" "jansson.h")
-bareosfindlibraryandheaders("rados" "rados/librados.h")
-bareosfindlibraryandheaders("radosstriper" "radosstriper/libradosstriper.h")
-bareosfindlibraryandheaders("cephfs" "cephfs/libcephfs.h")
 bareosfindlibraryandheaders("pthread" "pthread.h")
 bareosfindlibraryandheaders("cap" "sys/capability.h")
-bareosfindlibraryandheaders("gfapi" "glusterfs/api/glfs.h")
-bareosfindlibraryandheaders("droplet" "droplet.h")
+
+if(rados)
+  bareosfindlibraryandheaders("rados" "rados/librados.h")
+  bareosfindlibraryandheaders("radosstriper" "radosstriper/libradosstriper.h")
+endif()
+if(cephfs)
+  bareosfindlibraryandheaders("cephfs" "cephfs/libcephfs.h")
+endif()
+if(gfapi)
+  bareosfindlibraryandheaders("gfapi" "glusterfs/api/glfs.h")
+endif()
+if(droplet)
+  bareosfindlibraryandheaders("droplet" "droplet.h")
+endif()
 
 bareosfindlibraryandheaders("pam" "security/pam_appl.h")
 
