--- modules/shellcode-signatures/sch_namespace_base64.cpp.orig
+++ modules/shellcode-signatures/sch_namespace_base64.cpp
@@ -27,6 +27,8 @@
 
 /* $Id: sch_namespace_base64.cpp 693 2006-11-02 19:35:43Z common $ */
 
+#include <cstring>
+
 #include "sch_namespace_base64.hpp"
 
 #include "Nepenthes.hpp"
