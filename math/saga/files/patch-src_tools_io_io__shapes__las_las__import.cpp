--- src/tools/io/io_shapes_las/las_import.cpp.orig	2019-06-24 16:44:36 UTC
+++ src/tools/io/io_shapes_las/las_import.cpp
@@ -58,9 +58,9 @@
 ///////////////////////////////////////////////////////////
 
 //---------------------------------------------------------
-#include <liblas/laspoint.hpp>
-#include <liblas/lasreader.hpp>
-#include <liblas/capi/las_version.h>
+#include <liblas12/laspoint.hpp>
+#include <liblas12/lasreader.hpp>
+#include <liblas12/capi/las_version.h>
 #include <fstream>
 #include <iostream>
 
