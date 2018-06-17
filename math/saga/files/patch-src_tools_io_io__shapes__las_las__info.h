--- src/tools/io/io_shapes_las/las_info.h.orig	2018-05-01 09:07:11 UTC
+++ src/tools/io/io_shapes_las/las_info.h
@@ -76,9 +76,9 @@
 //---------------------------------------------------------
 #include "MLB_Interface.h"
 
-#include <liblas/laspoint.hpp>
-#include <liblas/lasreader.hpp>
-#include <liblas/capi/las_version.h>
+#include <liblas12/laspoint.hpp>
+#include <liblas12/lasreader.hpp>
+#include <liblas12/capi/las_version.h>
 #include <fstream>
 #include <iostream>
 
