--- modules/shellcode-generic/sch_generic_cmd.cpp.orig
+++ modules/shellcode-generic/sch_generic_cmd.cpp
@@ -30,6 +30,8 @@
 
 
 
+#include <cstring>
+
 #include "sch_generic_cmd.hpp"
 
 #include "Nepenthes.hpp"
