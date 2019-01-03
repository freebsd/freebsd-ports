--- lib/Application.vala.orig	2018-12-17 13:02:11 UTC
+++ lib/Application.vala
@@ -157,7 +157,11 @@ namespace Granite {
             message ("Kernel version: %s", (string) un.release);
             Granite.Services.Logger.DisplayLevel = Granite.Services.LogLevel.WARN;
 
-            Intl.bindtextdomain (exec_name, build_data_dir + "/locale");
+            Intl.setlocale (LocaleCategory.ALL, "");
+            string langpack_dir = Path.build_path (Path.DIR_SEPARATOR_S, build_data_dir, "locale");
+            Intl.bindtextdomain (exec_name, langpack_dir);
+            Intl.bind_textdomain_codeset (exec_name, "UTF-8");
+            Intl.textdomain (exec_name);
 
             handle_local_options.connect (on_handle_local_options);
         }
