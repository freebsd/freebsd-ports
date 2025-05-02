--- VTK/ThirdParty/diy2/vtkdiy2/include/vtkdiy2/log.hpp.orig	2024-12-29 23:38:49 UTC
+++ VTK/ThirdParty/diy2/vtkdiy2/include/vtkdiy2/log.hpp
@@ -4,8 +4,9 @@
 #ifndef DIY_USE_SPDLOG
 
 #include <memory>
-#include "fmt/format.h"
-#include "fmt/ostream.h"
+#include "vtk_fmt.h"
+#include VTK_FMT(fmt/format.h)
+#include VTK_FMT(fmt/ostream.h)
 
 namespace diy
 {
