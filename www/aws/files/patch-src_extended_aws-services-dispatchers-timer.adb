--- src/extended/aws-services-dispatchers-timer.adb.orig	2014-05-15 19:48:07 UTC
+++ src/extended/aws-services-dispatchers-timer.adb
@@ -480,7 +480,11 @@ package body AWS.Services.Dispatchers.Ti
 
    procedure Unregister
      (Dispatcher : in out Handler;
-      Name       : String) is
+      Name       : String)
+   is
+      use type Period_Table.Cursor;
+      
+      Pos : Period_table.Cursor := Period_Table.No_Element;
    begin
       for Cursor in Dispatcher.Table.Iterate loop
          declare
@@ -488,13 +492,18 @@ package body AWS.Services.Dispatchers.Ti
          begin
             if To_String (Item.Name) = Name then
                Unchecked_Free (Item);
-               Period_Table.Delete (Dispatcher.Table, Cursor);
-               return;
+               Pos := Cursor;
+               exit;
             end if;
          end;
       end loop;
 
-      raise Constraint_Error with "Timer distpatcher " & Name & " not found";
+      if Pos = Period_Table.No_Element then
+         raise Constraint_Error
+           with "Timer distpatcher " & Name & " not found";
+      else
+         Period_Table.Delete (Dispatcher.Table, Pos);
+      end if;
    end Unregister;
 
    ------------
