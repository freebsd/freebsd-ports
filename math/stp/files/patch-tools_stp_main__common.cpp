--- tools/stp/main_common.cpp.orig
+++ tools/stp/main_common.cpp
@@ -27,16 +27,8 @@
 #include "stp/Parser/parser.h"
 #include "stp/cpp_interface.h"
 
-//for srbk() function
-#if !defined(__MINGW32__) && !defined(__MINGW64__) && !defined(_MSC_VER)
-#include <unistd.h>
-#endif
-
 extern void errorHandler(const char* error_msg);
 
-// Amount of memory to ask for at beginning of main.
-extern const intptr_t INITIAL_MEMORY_PREALLOCATION_SIZE;
-
 using namespace stp;
 using std::unique_ptr;
 using std::cout;
@@ -49,9 +41,6 @@
   exit(-1);
 }
 
-// Amount of memory to ask for at beginning of main.
-const intptr_t INITIAL_MEMORY_PREALLOCATION_SIZE = 4000000;
-
 Main::Main() : onePrintBack(false)
 {
   bm = NULL;
@@ -62,15 +51,6 @@
 
   // Register the error handler
   vc_error_hdlr = errorHandler;
-
-#if !defined(__MINGW32__) && !defined(__MINGW64__) && !defined(_MSC_VER)
-  // Grab some memory from the OS upfront to reduce system time when
-  // individual hash tables are being allocated
-  if (sbrk(INITIAL_MEMORY_PREALLOCATION_SIZE) == ((void*)-1))
-  {
-    FatalError("Initial allocation of memory failed.");
-  }
-#endif
 
   bm = new STPMgr();
   GlobalParserBM = bm;
