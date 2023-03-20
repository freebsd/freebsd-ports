- unbreak bundled VTK after math/exprtk update to 0.0.2

--- VTK/Common/Misc/vtkExprTkFunctionParser.cxx.orig	2023-03-20 04:03:14 UTC
+++ VTK/Common/Misc/vtkExprTkFunctionParser.cxx
@@ -19,6 +19,7 @@
 #include <cctype>
 #include <random>
 #include <regex>
+#include <sstream>
 
 // exprtk macros
 #define exprtk_disable_string_capabilities
