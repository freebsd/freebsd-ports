--- include/ecif_inputFront.h~	Tue Jun 14 17:18:49 2005
+++ include/ecif_inputFront.h	Wed Jan 10 22:29:25 2007
@@ -65,7 +65,7 @@
   static bool readName(emf_ObjectData_X* od, char*& name);
   static int readVertex(emf_ObjectData_X* object_data);
   static int readVertexTable(emf_ObjectData_X* object_data);
-  static bool InputFront::storeMatcData(MatcValueTable& matcTable, const char* key, emf_ObjectData_X* od);
+  static bool storeMatcData(MatcValueTable& matcTable, const char* key, emf_ObjectData_X* od);
   static int unknownFieldMsg(emf_ObjectData_X* object_data, bool is_fatal = true);
   static int unknownObjectMsg(emf_ObjectData_X* object_data, bool is_fatal = true);
 
