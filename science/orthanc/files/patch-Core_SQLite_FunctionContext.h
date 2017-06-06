--- Core/SQLite/FunctionContext.h.orig	2016-06-27 11:02:35 UTC
+++ Core/SQLite/FunctionContext.h
@@ -37,7 +37,7 @@
 #include "Statement.h"
 
 struct sqlite3_context;
-struct Mem;  // This corresponds to the opaque type "sqlite3_value"
+struct sqlite3_value;  // This corresponds to the opaque type "sqlite3_value"
  
 namespace Orthanc
 {
@@ -50,14 +50,14 @@ namespace Orthanc
     private:
       struct sqlite3_context* context_;
       unsigned int argc_;
-      struct ::Mem** argv_;
+      struct sqlite3_value** argv_;
 
       void CheckIndex(unsigned int index) const;
 
     public:
       FunctionContext(struct sqlite3_context* context,
                       int argc,
-                      struct ::Mem** argv);
+                      struct sqlite3_value** argv);
 
       ColumnType GetColumnType(unsigned int index) const;
  
