--- cmake/modules/csiro.cmake.orig	2019-06-01 23:24:33 UTC
+++ cmake/modules/csiro.cmake
@@ -1,6 +1,7 @@
 # cmake/modules/csiro.cmake
 #
-# Copyright (C) 2006-2019  Alan W. Irwin
+# Copyright (C) 2006-2021  Alan W. Irwin
+# Patch borrowed from https://sourceforge.net/p/plplot/plplot/ci/52479b8830ee02900b41fe3ec947aed6b1841a48/
 #
 # This file is part of PLplot.
 #
@@ -72,30 +73,29 @@ if(PL_HAVE_QHULL OR WITH_CSA)
 endif(PL_HAVE_QHULL OR WITH_CSA)
 
 if(PL_HAVE_QHULL)
-  find_package(QHULL)
-  if(QHULL_FOUND)
-    message(STATUS "QHULL_INCLUDE_DIRS = ${QHULL_INCLUDE_DIRS}")
-    message(STATUS "HAS_LIBQHULL_INCLUDE = ${HAS_LIBQHULL_INCLUDE}")
-    message(STATUS "QHULL_LIBRARIES = ${QHULL_LIBRARIES}")
-    set(QHULL_RPATH ${QHULL_LIBRARY_DIRS})
+  find_package(Qhull CONFIG)
+  if(Qhull_FOUND)
+
+    # Determine QHULL_RPATH, the location of the qhull_r library.
+    get_target_property(QHULL_RPATH Qhull::qhull_r LOCATION)
+    # Transform from full pathname to path where qhull_r is located.
+    get_filename_component(QHULL_RPATH ${QHULL_RPATH} DIRECTORY)
+    message(STATUS "DEBUG: QHULL_RPATH = ${QHULL_RPATH}")
+    # Filter it to exclude system location, i.e., only need
+    # QHULL_RPATH for the case when qhull installed in a non-standard
+    # location.
     filter_rpath(QHULL_RPATH)
-    message(STATUS "QHULL_RPATH = ${QHULL_RPATH}")
+    message(STATUS "DEBUG: QHULL_RPATH = ${QHULL_RPATH}")
+
     include(CheckFunctionExists)
     cmake_push_check_state()
-    list(APPEND CMAKE_REQUIRED_LIBRARIES ${QHULL_LIBRARIES})
+    list(APPEND CMAKE_REQUIRED_LIBRARIES "-L${QHULL_RPATH} -lqhull_r")
     check_function_exists(qh_new_qhull QH_NEW_EXIST)
     cmake_pop_check_state()
-    if(NOT QH_NEW_EXIST)
-      message(STATUS "WARNING: function qh_new_qhull not found.  Setting PL_HAVE_QHULL to OFF.")
-      set(PL_HAVE_QHULL OFF CACHE BOOL "Enable use of the Qhull library" FORCE)
-    endif(NOT QH_NEW_EXIST)
-    if(HAS_LIBQHULL_INCLUDE)
-      file(WRITE ${CMAKE_CURRENT_BINARY_DIR}/Check_realT_size.c "#include <libqhull/qhull_a.h>")
-    else(HAS_LIBQHULL_INCLUDE)
-      file(WRITE ${CMAKE_CURRENT_BINARY_DIR}/Check_realT_size.c "#include <qhull/qhull_a.h>")
-    endif(HAS_LIBQHULL_INCLUDE)
-    file(APPEND ${CMAKE_CURRENT_BINARY_DIR}/Check_realT_size.c
-      "
+    if(QH_NEW_EXIST)
+      file(WRITE ${CMAKE_CURRENT_BINARY_DIR}/Check_realT_size.c "#include <libqhull_r/qhull_ra.h>")
+      file(APPEND ${CMAKE_CURRENT_BINARY_DIR}/Check_realT_size.c
+	"
 int main(void)
 {
   if ( sizeof ( realT ) != sizeof ( double ) )
@@ -104,33 +104,34 @@ int main(void)
     return 0;
 }
 "
-      )
-    try_run(RUN_RESULT COMPILE_RESULT
-      ${CMAKE_CURRENT_BINARY_DIR}
-      ${CMAKE_CURRENT_BINARY_DIR}/Check_realT_size.c
-      CMAKE_FLAGS "-DCOMPILE_DEFINITIONS:STRING=-I\"${QHULL_INCLUDE_DIRS}\""
-      OUTPUT_VARIABLE OUTPUT
-      )
-    #message(STATUS "Check_realT_size COMPILE_RESULT = ${COMPILE_RESULT}")
-    #message(STATUS "Check_realT_size RUN_RESULT = ${RUN_RESULT}")
-    if(NOT COMPILE_RESULT OR RUN_RESULT MATCHES "FAILED_TO_RUN")
-      message(STATUS "Either could not compile or could not run code to check wrong size for realT in qhull library.  Dropping qhull librarydependency of PLplot.")
-      set(PL_HAVE_QHULL OFF CACHE BOOL "Enable use of the Qhull library" FORCE)
-    endif(NOT COMPILE_RESULT OR RUN_RESULT MATCHES "FAILED_TO_RUN")
+	)
+      try_run(RUN_RESULT COMPILE_RESULT
+	${CMAKE_CURRENT_BINARY_DIR}
+	${CMAKE_CURRENT_BINARY_DIR}/Check_realT_size.c
+	OUTPUT_VARIABLE OUTPUT
+	)
+      #message(STATUS "Check_realT_size COMPILE_RESULT = ${COMPILE_RESULT}")
+      #message(STATUS "Check_realT_size RUN_RESULT = ${RUN_RESULT}")
+      if(NOT COMPILE_RESULT OR RUN_RESULT MATCHES "FAILED_TO_RUN")
+	message(STATUS "Either could not compile or could not run code to check wrong size for realT in qhull library.  Dropping qhull librarydependency of PLplot.")
+	set(PL_HAVE_QHULL OFF CACHE BOOL "Enable use of the Qhull library" FORCE)
+      endif(NOT COMPILE_RESULT OR RUN_RESULT MATCHES "FAILED_TO_RUN")
 
-    if(RUN_RESULT)
-      message(STATUS "qhull library compiled with incorrect (non-double) size for realT.  Dropping qhull dependency of PLplot.")
+      if(RUN_RESULT)
+	message(STATUS "qhull library compiled with incorrect (non-double) size for realT.  Dropping qhull dependency of PLplot.")
+	set(PL_HAVE_QHULL OFF CACHE BOOL "Enable use of the Qhull library" FORCE)
+      else(RUN_RESULT)
+	message(STATUS "qhull library compiled with correct (double) size for realT.")
+      endif(RUN_RESULT)
+    else(QH_NEW_EXIST)
+      message(STATUS "WARNING: function qh_new_qhull not found.  Setting PL_HAVE_QHULL to OFF.")
       set(PL_HAVE_QHULL OFF CACHE BOOL "Enable use of the Qhull library" FORCE)
-    else(RUN_RESULT)
-      message(STATUS "qhull library compiled with correct (double) size for realT.")
-    endif(RUN_RESULT)
+    endif(QH_NEW_EXIST)
 
-  else(QHULL_FOUND)
-    message(STATUS "QHULL_INCLUDE_DIRS = ${QHULL_INCLUDE_DIRS}")
-    message(STATUS "QHULL_LIBRARIES = ${QHULL_LIBRARIES}")
+  else(Qhull_FOUND)
     message(STATUS
-      "WARNING: at least one of QHULL_INCLUDE_DIRS or QHULL_LIBRARIES is false so setting PL_HAVE_QHULL to OFF."
-      )
+      "WARNING: Qhull package not found in CONFIG mode.  The required CONFIG mode files only available for later releases of qhull so perhaps you need to update your qhull version?")
+    message(STATUS "setting PL_HAVE_QHULL to OFF.")
     set(PL_HAVE_QHULL OFF CACHE BOOL "Enable use of the Qhull library" FORCE)
-  endif(QHULL_FOUND)
+  endif(Qhull_FOUND)
 endif(PL_HAVE_QHULL)
