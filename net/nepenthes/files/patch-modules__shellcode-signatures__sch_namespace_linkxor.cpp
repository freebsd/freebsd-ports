--- modules/shellcode-signatures/sch_namespace_linkxor.cpp.orig
+++ modules/shellcode-signatures/sch_namespace_linkxor.cpp
@@ -28,6 +28,8 @@
 /* $Id: sch_namespace_linkxor.cpp 654 2006-09-27 12:01:16Z common $ */
 
 
+#include <cstring>
+
 #include "sch_namespace_linkxor.hpp"
 
 #include "Nepenthes.hpp"
