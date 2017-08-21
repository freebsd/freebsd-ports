--- aux/broker/cmake/FindCAF.cmake.orig	2016-11-16 22:53:56 UTC
+++ aux/broker/cmake/FindCAF.cmake
@@ -10,6 +10,8 @@
 #  CAF_ROOT_DIR  Set this variable either to an installation prefix or to wa
 #                CAF build directory where to look for the CAF libraries.
 #
+#  CAF_STATIC_ONLY  Find the static libraries of caf only.
+#
 # Variables defined by this module:
 #
 #  CAF_FOUND              System has CAF headers and library
@@ -34,11 +36,18 @@ foreach (comp ${CAF_FIND_COMPONENTS})
         "${CAF_ROOT_DIR}/include"
         "${CAF_ROOT_DIR}/../libcaf_${comp}")
   endif ()
+  # give CAF_ROOT_DIR priority...
+  find_path(CAF_INCLUDE_DIR_${UPPERCOMP}
+            NAMES
+              ${HDRNAME}
+            HINTS
+	      ${header_hints}
+	    NO_DEFAULT_PATH)
+  # ...then look in default locations if not found yet
   find_path(CAF_INCLUDE_DIR_${UPPERCOMP}
             NAMES
               ${HDRNAME}
             HINTS
-              ${header_hints}
               /usr/include
               /usr/local/include
               /opt/local/include
@@ -65,11 +74,24 @@ foreach (comp ${CAF_FIND_COMPONENTS})
       if (CAF_ROOT_DIR)
         set(library_hints "${CAF_ROOT_DIR}/lib")
       endif ()
+      # Find dynamic or static library
+      if (CAF_STATIC_ONLY)
+        set(library_name "caf_${comp}_static")
+      else ()
+        set(library_name "caf_${comp}")
+      endif ()
+      # give CAF_ROOT_DIR priority...
       find_library(CAF_LIBRARY_${UPPERCOMP}
                    NAMES
-                     "caf_${comp}"
+                     ${library_name}
                    HINTS
                      ${library_hints}
+		     NO_DEFAULT_PATH)
+      # ...then look in default locations if not found yet
+      find_library(CAF_LIBRARY_${UPPERCOMP}
+                   NAMES
+                     ${library_name}
+                   HINTS
                      /usr/lib
                      /usr/local/lib
                      /opt/local/lib
