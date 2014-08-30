--- modules/shellcode-signatures/sch_namespace_alphanumericxor.cpp.orig
+++ modules/shellcode-signatures/sch_namespace_alphanumericxor.cpp
@@ -28,6 +28,8 @@
 /* $Id: sch_namespace_alphanumericxor.cpp 520 2006-04-18 23:18:17Z common $ */
 
 
+#include <cstring>
+
 #include "sch_namespace_alphanumericxor.hpp"
 
 #include "Nepenthes.hpp"
