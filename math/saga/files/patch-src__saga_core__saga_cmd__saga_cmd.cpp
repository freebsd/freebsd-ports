--- src/saga_core/saga_cmd/saga_cmd.cpp.orig	2014-03-28 16:06:55.000000000 +0100
+++ src/saga_core/saga_cmd/saga_cmd.cpp	2014-03-28 16:09:04.000000000 +0100
@@ -65,6 +65,7 @@
 
 #include <wx/app.h>
 #include <wx/utils.h>
+#include <clocale>
 
 #include "callback.h"
 
@@ -164,7 +165,7 @@
 //---------------------------------------------------------
 bool		Run(int argc, char *argv[])
 {
-	setlocale(LC_NUMERIC, "C");
+	std::setlocale(LC_NUMERIC, "C");
 
 	SG_Set_UI_Callback(CMD_Get_Callback());
 
