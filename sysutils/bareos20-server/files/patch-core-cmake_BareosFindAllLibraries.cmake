--- core/cmake/BareosFindAllLibraries.cmake	2021-06-10 10:37:18.000000000 -0500
+++ core/cmake/BareosFindAllLibraries.cmake	2021-07-09 21:07:45.799522000 -0500
@@ -37,55 +37,39 @@
   set(Python3_FOUND 0)
 
 else()
-  find_package(Python2 COMPONENTS Interpreter Development)
-  find_package(Python3 COMPONENTS Interpreter Development)
+  if(python)
+    find_package(Python3 COMPONENTS Interpreter Development)
 
-  set(Python3_VERSION_MAJOR
-      ${Python3_VERSION_MAJOR}
-      PARENT_SCOPE
-  )
-
-  set(Python3_VERSION_MINOR
-      ${Python3_VERSION_MINOR}
-      PARENT_SCOPE
-  )
-
-  if(${Python2_FOUND} OR ${Python3_FOUND})
-    set(HAVE_PYTHON 1)
-  endif()
-
-  if(${Python2_FOUND})
-    set(PYTHON_EXECUTABLE
-        ${Python2_EXECUTABLE}
+    set(Python3_VERSION_MAJOR
+        ${Python3_VERSION_MAJOR}
         PARENT_SCOPE
     )
-    set(Python2_EXECUTABLE
-        ${Python2_EXECUTABLE}
-        PARENT_SCOPE
-    )
-    execute_process(
-      COMMAND ${Python2_EXECUTABLE}
-              ${CMAKE_CURRENT_SOURCE_DIR}/cmake/get_python_compile_settings.py
-      OUTPUT_FILE ${CMAKE_CURRENT_BINARY_DIR}/py2settings.cmake
-    )
-    include(${CMAKE_CURRENT_BINARY_DIR}/py2settings.cmake)
-  endif()
 
-  if(${Python3_FOUND})
-    set(PYTHON_EXECUTABLE
-        ${Python3_EXECUTABLE}
+    set(Python3_VERSION_MINOR
+        ${Python3_VERSION_MINOR}
         PARENT_SCOPE
     )
-    set(Python3_EXECUTABLE
-        ${Python3_EXECUTABLE}
-        PARENT_SCOPE
-    )
-    execute_process(
-      COMMAND ${Python3_EXECUTABLE}
-              ${CMAKE_CURRENT_SOURCE_DIR}/cmake/get_python_compile_settings.py
-      OUTPUT_FILE ${CMAKE_CURRENT_BINARY_DIR}/py3settings.cmake
-    )
-    include(${CMAKE_CURRENT_BINARY_DIR}/py3settings.cmake)
+
+    if(${Python3_FOUND})
+      set(HAVE_PYTHON 1)
+    endif()
+
+    if(${Python3_FOUND})
+      set(PYTHON_EXECUTABLE
+          ${Python3_EXECUTABLE}
+          PARENT_SCOPE
+      )
+      set(Python3_EXECUTABLE
+          ${Python3_EXECUTABLE}
+          PARENT_SCOPE
+      )
+      execute_process(
+        COMMAND ${Python3_EXECUTABLE}
+                ${CMAKE_CURRENT_SOURCE_DIR}/cmake/get_python_compile_settings.py
+        OUTPUT_FILE ${CMAKE_CURRENT_BINARY_DIR}/py3settings.cmake
+      )
+      include(${CMAKE_CURRENT_BINARY_DIR}/py3settings.cmake)
+    endif()
   endif()
 endif()
 
@@ -164,12 +148,18 @@
 endif()
 
 bareosfindlibraryandheaders("jansson" "jansson.h" "")
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
 
