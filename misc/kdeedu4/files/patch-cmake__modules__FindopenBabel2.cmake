diff -u ../cmake/modules/FindOpenBabel2.cmake ../cmake/modules/FindOpenBabel2.cmake
--- ../cmake/modules/FindOpenBabel2.cmake	2009/01/25 12:06:30	916420
+++ ../cmake/modules/FindOpenBabel2.cmake	2009/01/26 22:11:35	917115
@@ -4,6 +4,7 @@
 #  OPENBABEL2_FOUND - system has OpenBabel2
 #  OPENBABEL2_INCLUDE_DIR - the OpenBabel2 include directory
 #  OPENBABEL2_LIBRARIES - Link these to use OpenBabel2
+# Copyright (C) 2006, 2009 Pino Toscano, <pino@kde.org>
 # Copyright (c) 2006, 2007 Carsten Niehaus, <cniehaus@gmx.de>
 # Copyright (C) 2008 Marcus D. Hanwell <marcus@cryos.org>
 # Redistribution and use is allowed according to the terms of the BSD license.
@@ -18,13 +19,11 @@
 
     # Use the newer PkgConfig stuff
     find_package(PkgConfig REQUIRED)
-    pkg_check_modules(OPENBABEL2 openbabel-2.0>=2.2.0)
+    pkg_check_modules(PC_OPENBABEL2 openbabel-2.0>=2.2.0)
 
-    # Maintain backwards compatibility with previous version of module
-    if(OPENBABEL2_FOUND STREQUAL "1")
+    if(PC_OPENBABEL2_FOUND)
       set(OPENBABEL2_VERSION_MET TRUE)
-      set(OPENBABEL2_INCLUDE_DIR ${OPENBABEL2_INCLUDE_DIRS})
-    endif(OPENBABEL2_FOUND STREQUAL "1")
+    endif(PC_OPENBABEL2_FOUND)
 
   else(NOT WIN32)
     set(OPENBABEL2_VERSION_MET TRUE)
@@ -32,28 +31,19 @@
 
   if(OPENBABEL2_VERSION_MET)
 
-   # find_path(OPENBABEL2_INCLUDE_DIR openbabel/obconversion.h
-   #   PATHS
-   #   ${_obIncDir}
-   #   ${GNUWIN32_DIR}/include
-   #   $ENV{OPENBABEL2_INCLUDE_DIR}
-   # )
-
-    if(WIN32)
-      if(NOT OPENBABEL2_INCLUDE_DIR)
-        find_path(OPENBABEL2_INCLUDE_DIR openbabel/obconversion.h
-          PATHS
-          ${_obIncDir}
-          ${GNUWIN32_DIR}/include
-          $ENV{OPENBABEL2_INCLUDE_DIR}
-          PATH_SUFFIXES openbabel-2.0
-        )
-      endif(NOT OPENBABEL2_INCLUDE_DIR)
-    endif(WIN32)
+    find_path(OPENBABEL2_INCLUDE_DIR openbabel/obconversion.h
+      PATHS
+      ${PC_OPENBABEL2_INCLUDEDIR}
+      ${PC_OPENBABEL2_INCLUDE_DIRS}
+      ${GNUWIN32_DIR}/include
+      $ENV{OPENBABEL2_INCLUDE_DIR}
+      PATH_SUFFIXES openbabel-2.0
+    )
 
-    find_library(OPENBABEL2_LIBRARIES NAMES openbabel
+    find_library(OPENBABEL2_LIBRARIES NAMES openbabel openbabel-2
       PATHS
-      ${_obLinkDir}
+      ${PC_OPENBABEL2_LIBDIR}
+      ${PC_OPENBABEL2_LIBRARY_DIRS}
       ${GNUWIN32_DIR}/lib
       $ENV{OPENBABEL2_LIBRARIES}
     )
