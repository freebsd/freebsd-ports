--- Core/SQLite/FunctionContext.cpp.orig	2016-06-27 11:02:35 UTC
+++ Core/SQLite/FunctionContext.cpp
@@ -49,7 +49,7 @@ namespace Orthanc
   {
     FunctionContext::FunctionContext(struct sqlite3_context* context,
                                      int argc,
-                                     struct ::Mem** argv)
+                                     struct sqlite3_value** argv)
     {
       assert(context != NULL);
       assert(argc >= 0);
