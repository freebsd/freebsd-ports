--- Source/WebInspectorUI/Scripts/update-LegacyInspectorBackendCommands.rb.orig	2021-05-17 13:22:42 UTC
+++ Source/WebInspectorUI/Scripts/update-LegacyInspectorBackendCommands.rb
@@ -36,7 +36,7 @@ class Task
       end
 
       generated_path = File.join tmpdir, output_filename
-      if !File.exists?(generated_path)
+      if !File.exist?(generated_path)
         puts "ERROR: Generated file does not exist at expected path."
         exit 1
       end
