--- schema/schema-validators-restrictions.adb.orig	Tue Jan  2 10:28:58 2007
+++ schema/schema-validators-restrictions.adb	Tue Jan  2 10:30:55 2007
@@ -201,7 +201,7 @@
    begin
       Had_Restriction := True;
 
-      if Validator.Base.Block_Restriction and then Had_Restriction then
+      if Validator.Base.Block_Restriction then
          Validation_Error
            ("Restrictions of type """
             & Get_Local_Name (Validator.Base) & """ are forbidden");
