--- schema/schema-validators-extensions.adb.orig	Tue Jan  2 10:16:54 2007
+++ schema/schema-validators-extensions.adb	Tue Jan  2 10:19:58 2007
@@ -199,13 +199,13 @@
    begin
       Had_Extension := True;
 
-      if Validator.Base.Block_Restriction and then Had_Restriction then
+      if Validator.Base.Block_Restriction then
          Validation_Error
            ("Restrictions of type """
             & Get_Local_Name (Validator.Base) & """ are forbidden");
       end if;
 
-      if Validator.Base.Block_Extension and then Had_Extension then
+      if Validator.Base.Block_Extension then
          Validation_Error
            ("Extensions of type """
             & Get_Local_Name (Validator.Base) & """ are forbidden");
