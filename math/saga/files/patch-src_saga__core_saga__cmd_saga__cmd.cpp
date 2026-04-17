--- src/saga_core/saga_cmd/saga_cmd.cpp.orig	2026-04-10 09:39:33 UTC
+++ src/saga_core/saga_cmd/saga_cmd.cpp
@@ -51,6 +51,7 @@
 #include <wx/app.h>
 #include <wx/utils.h>
 #include <wx/filename.h>
+#include <clocale>
 
 #include "config.h"
 #include "callback.h"
@@ -186,7 +187,7 @@ bool		Run(int argc, char *argv[])
 //---------------------------------------------------------
 bool		Run(int argc, char *argv[])
 {
-	setlocale(LC_NUMERIC, "C");
+	std::setlocale(LC_NUMERIC, "C");
 
 	SG_Set_UI_Callback(CMD_Get_Callback());
 
