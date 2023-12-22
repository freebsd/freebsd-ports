--- src/saga_core/saga_cmd/saga_cmd.cpp.orig	2023-12-11 15:05:42 UTC
+++ src/saga_core/saga_cmd/saga_cmd.cpp
@@ -50,6 +50,7 @@
 
 #include <wx/app.h>
 #include <wx/utils.h>
+#include <clocale>
 
 #include "config.h"
 #include "callback.h"
@@ -163,7 +164,7 @@ bool		Run(int argc, char *argv[])
 //---------------------------------------------------------
 bool		Run(int argc, char *argv[])
 {
-	setlocale(LC_NUMERIC, "C");
+	std::setlocale(LC_NUMERIC, "C");
 
 	SG_Set_UI_Callback(CMD_Get_Callback());
 
