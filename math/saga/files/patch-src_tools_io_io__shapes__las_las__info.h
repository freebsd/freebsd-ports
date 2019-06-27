--- src/tools/io/io_shapes_las/las_info.h.orig	2019-06-24 16:47:07 UTC
+++ src/tools/io/io_shapes_las/las_info.h
@@ -74,9 +74,9 @@
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
 
