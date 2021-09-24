--- src/saga_core/saga_cmd/saga_cmd.cpp.orig	2020-02-07 16:57:34 UTC
+++ src/saga_core/saga_cmd/saga_cmd.cpp
@@ -52,6 +52,7 @@
 
 #include <wx/app.h>
 #include <wx/utils.h>
+#include <clocale>
 
 #include "config.h"
 #include "callback.h"
@@ -165,7 +166,7 @@ _except(1)
 //---------------------------------------------------------
 bool		Run(int argc, char *argv[])
 {
-	setlocale(LC_NUMERIC, "C");
+	std::setlocale(LC_NUMERIC, "C");
 
 	SG_Set_UI_Callback(CMD_Get_Callback());
 
