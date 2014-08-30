--- nepenthes-core/src/LogManager.cpp.orig
+++ nepenthes-core/src/LogManager.cpp
@@ -27,9 +27,11 @@
 
 /* $Id: LogManager.cpp 836 2007-02-06 15:16:50Z common $ */
 
-#include <stdarg.h>
-#include <assert.h>
-#include <stdio.h>
+#include <cstdarg>
+#include <cassert>
+#include <cstdio>
+#include <cstdlib>
+#include <cstring>
 #include "LogManager.hpp"
 #include "LogHandlerEntry.hpp"
 #include "LogHandler.hpp"
