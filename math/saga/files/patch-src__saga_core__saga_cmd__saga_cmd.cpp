--- ./src/saga_core/saga_cmd/saga_cmd.cpp.orig	2013-07-01 16:16:32.000000000 +0200
+++ ./src/saga_core/saga_cmd/saga_cmd.cpp	2014-03-24 16:05:03.000000000 +0100
@@ -64,6 +64,8 @@
 #include <wx/app.h>
 #include <wx/utils.h>
 
+#include <locale.h>
+
 #include "callback.h"
 
 #include "module_library.h"
