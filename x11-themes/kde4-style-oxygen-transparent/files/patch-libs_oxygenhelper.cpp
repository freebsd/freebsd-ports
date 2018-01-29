--- libs/oxygenhelper.cpp.orig	2018-01-29 16:36:56 UTC
+++ libs/oxygenhelper.cpp
@@ -1117,7 +1117,7 @@ namespace Oxygen
             &data);
 
         // finish if no data is found
-        if( data == None || n != 1 ) return false;
+        if( data == NULL || n != 1 ) return false;
         else return *data;
 
     }
