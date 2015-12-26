--- src/saga_core/saga_api/table_io.cpp.orig	2015-12-21 09:38:29 UTC
+++ src/saga_core/saga_api/table_io.cpp
@@ -118,7 +118,7 @@ bool CSG_Table::Load(const CSG_String &F
 //---------------------------------------------------------
 bool CSG_Table::Save(const CSG_String &File_Name, int Format)
 {
-	return( Save(File_Name, Format, NULL) );
+	return( Save(File_Name, Format, '\0') );
 }
 
 //---------------------------------------------------------
