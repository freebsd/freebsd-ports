--- src/parameters.adb.orig	2024-06-17 13:37:33.229523000 +1200
+++ src/parameters.adb	2024-06-17 13:35:59.280062000 +1200
@@ -50,7 +50,7 @@
          end;
       end if;

-      internal_config.Init (File_Name => conf_location,
+      internal_config.Init (Config_File_Name => conf_location,
                             On_Type_Mismatch => Config.Be_Quiet);

       if section_exists (master_section, global_01) then
