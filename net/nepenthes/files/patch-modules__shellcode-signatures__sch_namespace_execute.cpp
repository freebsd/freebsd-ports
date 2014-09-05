--- modules/shellcode-signatures/sch_namespace_execute.cpp.orig
+++ modules/shellcode-signatures/sch_namespace_execute.cpp
@@ -27,6 +27,8 @@
 
 /* $Id: sch_namespace_execute.cpp 550 2006-05-04 10:25:35Z common $ */
 
+#include <cstring>
+
 #include "sch_namespace_execute.hpp"
 
 #include "Nepenthes.hpp"
