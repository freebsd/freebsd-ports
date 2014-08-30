--- modules/shellcode-generic/sch_generic_createprocess.cpp.orig
+++ modules/shellcode-generic/sch_generic_createprocess.cpp
@@ -40,6 +40,9 @@
 
 
 
+#include <cstdio>
+#include <cstring>
+
 #include "sch_generic_createprocess.hpp"
 
 #include "Nepenthes.hpp"
