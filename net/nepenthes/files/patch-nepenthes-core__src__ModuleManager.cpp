--- nepenthes-core/src/ModuleManager.cpp.orig
+++ nepenthes-core/src/ModuleManager.cpp
@@ -27,6 +27,8 @@
 
 /* $Id: ModuleManager.cpp 612 2006-08-10 15:31:56Z common $ */
 
+#include <cstdio>
+#include <cstdlib>
 #include <dlfcn.h>
 
 #include "ModuleManager.hpp"
