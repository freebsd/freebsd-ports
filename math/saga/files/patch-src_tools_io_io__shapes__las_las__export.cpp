--- src/tools/io/io_shapes_las/las_export.cpp.orig	2019-06-24 16:41:27 UTC
+++ src/tools/io/io_shapes_las/las_export.cpp
@@ -59,9 +59,9 @@
 ///////////////////////////////////////////////////////////
 
 //---------------------------------------------------------
-#include <liblas/laspoint.hpp>
-#include <liblas/laswriter.hpp>
-#include <liblas/capi/las_version.h>
+#include <liblas12/laspoint.hpp>
+#include <liblas12/laswriter.hpp>
+#include <liblas12/capi/las_version.h>
 #include <fstream>
 #include <iostream>
 #include <cstddef>
