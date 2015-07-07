--- src/saga_core/saga_cmd/saga_cmd.cpp.orig	2015-02-26 07:51:10 UTC
+++ src/saga_core/saga_cmd/saga_cmd.cpp
@@ -65,6 +65,7 @@
 
 #include <wx/app.h>
 #include <wx/utils.h>
+#include <clocale>
 
 #include "callback.h"
 
@@ -164,7 +165,7 @@ _except(1)
 //---------------------------------------------------------
 bool		Run(int argc, char *argv[])
 {
-	setlocale(LC_NUMERIC, "C");
+	std::setlocale(LC_NUMERIC, "C");
 
 	SG_Set_UI_Callback(CMD_Get_Callback());
 
