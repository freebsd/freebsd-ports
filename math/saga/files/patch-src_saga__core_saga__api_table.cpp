--- src/saga_core/saga_api/table.cpp.orig	2015-12-21 09:38:29 UTC
+++ src/saga_core/saga_api/table.cpp
@@ -175,7 +175,7 @@ bool CSG_Table::Create(const CSG_String 
 	SG_UI_Msg_Add(CSG_String::Format("%s: %s...", _TL("Load table"), File_Name.c_str()), true);
 
 	//-----------------------------------------------------
-	bool	bResult	= File_Name.BeforeFirst(':').Cmp("PGSQL") && SG_File_Exists(File_Name) && Load(File_Name, (int)Format, NULL);
+	bool	bResult	= File_Name.BeforeFirst(':').Cmp("PGSQL") && SG_File_Exists(File_Name) && Load(File_Name, (int)Format, '\0');
 
 	if( bResult )
 	{
