--- prog/aspell.cpp.orig	2011-07-04 11:13:58.000000000 +0200
+++ prog/aspell.cpp	2014-02-11 22:42:04.000000000 +0100
@@ -25,6 +25,7 @@
 # include <langinfo.h>
 #endif
 
+#include "errors.hpp"
 #include "aspell.h"
 
 #ifdef USE_FILE_INO
@@ -40,7 +41,6 @@
 #include "convert.hpp"
 #include "document_checker.hpp"
 #include "enumeration.hpp"
-#include "errors.hpp"
 #include "file_util.hpp"
 #include "fstream.hpp"
 #include "info.hpp"
