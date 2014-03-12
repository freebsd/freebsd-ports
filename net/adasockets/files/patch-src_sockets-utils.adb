--- src/sockets-utils.adb.orig	2012-04-26 14:54:46.000000000 +0000
+++ src/sockets-utils.adb
@@ -73,10 +73,10 @@ package body Sockets.Utils is
          declare
             Current : Character renames Something (Index);
          begin
-            if (Current < '0'
-                or else Current > '9')
-              and then Current /= '.' then
-               return False;
+            if Current < '0' or else Current > '9' then
+               if Current /= '.' then
+                  return False;
+               end if;
             end if;
          end;
       end loop;
