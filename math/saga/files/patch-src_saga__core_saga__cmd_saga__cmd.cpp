--- src/saga_core/saga_cmd/saga_cmd.cpp.orig	2018-11-22 07:53:06 UTC
+++ src/saga_core/saga_cmd/saga_cmd.cpp
@@ -64,6 +64,7 @@
 
 #include <wx/app.h>
 #include <wx/utils.h>
+#include <clocale>
 
 #include "config.h"
 #include "callback.h"
@@ -168,7 +169,7 @@ _except(1)
 //---------------------------------------------------------
 bool		Run(int argc, char *argv[])
 {
-	setlocale(LC_NUMERIC, "C");
+	std::setlocale(LC_NUMERIC, "C");
 
 	SG_Set_UI_Callback(CMD_Get_Callback());
 
