--- modules/shellcode-signatures/sch_namespace_konstanzxor.cpp.orig
+++ modules/shellcode-signatures/sch_namespace_konstanzxor.cpp
@@ -27,6 +27,8 @@
 
 /* $Id: sch_namespace_konstanzxor.cpp 499 2006-04-08 18:40:14Z common $ */
 
+#include <cstring>
+
 #include "sch_namespace_konstanzxor.hpp"
 
 #include "Nepenthes.hpp"
