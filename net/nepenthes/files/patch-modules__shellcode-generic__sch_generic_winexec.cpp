--- modules/shellcode-generic/sch_generic_winexec.cpp.orig
+++ modules/shellcode-generic/sch_generic_winexec.cpp
@@ -29,6 +29,8 @@
 
 
 
+#include <cstring>
+
 #include "sch_generic_winexec.hpp"
 
 #include "Nepenthes.hpp"
