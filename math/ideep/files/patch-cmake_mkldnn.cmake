--- cmake/mkldnn.cmake.orig	2019-08-30 01:57:18 UTC
+++ cmake/mkldnn.cmake
@@ -17,7 +17,7 @@ if (USE_MKLDNN_INTERNAL)
 else()
   include(${CMAKE_ROOT}/Modules/ExternalProject.cmake)
   # find mkldnn first
-  set(mkldnn_PREFIX ${PROJECT_SOURCE_DIR}/mkl-dnn)
+  set(mkldnn_PREFIX ${CMAKE_INSTALL_PREFIX})
 
   if (UNIX)
     set(MKLDNN_EXTRA_COMPILER_FLAGS "-fPIC")
@@ -27,20 +27,20 @@ else()
   set(MKLDNN_CXX_FLAGS ${CMAKE_CXX_FLAGS} ${MKLDNN_EXTRA_COMPILER_FLAGS})
   set(MKLDNN_C_FLAGS ${CMAKE_C_FLAGS} ${MKLDNN_EXTRA_COMPILER_FLAGS})
 
-  ExternalProject_Add(mkldnn_exernal
-    SOURCE_DIR ${mkldnn_PREFIX}
-    BUILD_IN_SOURCE 1
-    CMAKE_ARGS
-      "-DCMAKE_CCXX_FLAGS=${MKLDNN_CCXX_FLAGS}"
-      "-DCMAKE_CXX_FLAGS=${MKLDNN_CXX_FLAGS}"
-      "-DCMAKE_C_FLAGS=${MKLDNN_C_FLAGS}"
-  )
+  #ExternalProject_Add(mkldnn_exernal
+  #  SOURCE_DIR ${mkldnn_PREFIX}
+  #  BUILD_IN_SOURCE 1
+  #  CMAKE_ARGS
+  #    "-DCMAKE_CCXX_FLAGS=${MKLDNN_CCXX_FLAGS}"
+  #    "-DCMAKE_CXX_FLAGS=${MKLDNN_CXX_FLAGS}"
+  #    "-DCMAKE_C_FLAGS=${MKLDNN_C_FLAGS}"
+  #)
 
-  ExternalProject_Add_Step(mkldnn_exernal
-    prepare_mkl
-    DEPENDERS configure
-    COMMAND ${mkldnn_PREFIX}/script/prepare_mkl.sh
-  )
+  #ExternalProject_Add_Step(mkldnn_exernal
+  #  prepare_mkl
+  #  DEPENDERS configure
+  #  COMMAND ${mkldnn_PREFIX}/script/prepare_mkl.sh
+  #)
 
   set(MKLDNN_FOUND TRUE)
   set(MKLDNN_INTERNAL TRUE)
