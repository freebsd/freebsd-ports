--- ./VTK/CMake/FindPNG.cmake.orig	Thu Jan  1 00:00:00 1970
+++ ./VTK/CMake/FindPNG.cmake	Sun Aug  6 10:16:48 2006
@@ -0,0 +1,27 @@
+#
+# Find the native PNG includes and library
+#
+# This module defines
+# PNG_INCLUDE_DIR, where to find png.h, etc.
+# PNG_LIBRARIES, the libraries to link against to use PNG.
+# PNG_FOUND, If false, do not try to use PNG.
+
+# also defined, but not for general use are
+# PNG_LIBRARY, where to find the PNG library.
+
+FIND_PATH(PNG_INCLUDE_DIR png.h
+  /usr/local/include
+  /usr/include
+)
+
+FIND_LIBRARY(PNG_LIBRARY png
+  /usr/lib
+  /usr/local/lib
+)
+
+IF(PNG_INCLUDE_DIR)
+  IF(PNG_LIBRARY)
+    SET( PNG_FOUND "YES" )
+    SET( PNG_LIBRARIES ${PNG_LIBRARY} )
+  ENDIF(PNG_LIBRARY)
+ENDIF(PNG_INCLUDE_DIR)
