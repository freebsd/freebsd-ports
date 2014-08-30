--- modules/shellcode-signatures/sch_namespace_xor.cpp.orig
+++ modules/shellcode-signatures/sch_namespace_xor.cpp
@@ -28,6 +28,8 @@
 /* $Id: sch_namespace_xor.cpp 499 2006-04-08 18:40:14Z common $ */
 
 
+#include <cstring>
+
 #include "sch_namespace_xor.hpp"
 
 #include "Nepenthes.hpp"
