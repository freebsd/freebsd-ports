Index: Source/JavaScriptCore/jsc.cpp
--- Source/JavaScriptCore/jsc.cpp.orig
+++ Source/JavaScriptCore/jsc.cpp
@@ -78,6 +78,7 @@
 #include "WasmCapabilities.h"
 #include "WasmFaultSignalHandler.h"
 #include "WasmMemory.h"
+#include <locale.h> /* LC_ALL */
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
