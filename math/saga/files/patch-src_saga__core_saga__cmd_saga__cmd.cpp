--- src/saga_core/saga_cmd/saga_cmd.cpp.orig	2024-07-29 13:42:28 UTC
+++ src/saga_core/saga_cmd/saga_cmd.cpp
@@ -51,6 +51,7 @@
 #include <wx/app.h>
 #include <wx/utils.h>
 #include <wx/filename.h>
+#include <clocale>
 
 #include "config.h"
 #include "callback.h"
@@ -165,7 +166,7 @@ bool		Run(int argc, char *argv[])
 //---------------------------------------------------------
 bool		Run(int argc, char *argv[])
 {
-	setlocale(LC_NUMERIC, "C");
+	std::setlocale(LC_NUMERIC, "C");
 
 	SG_Set_UI_Callback(CMD_Get_Callback());
 
