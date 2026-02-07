--- extras/gtk2_immodule/gtkimcontextscim.cpp.orig	2008-11-02 07:43:15.000000000 +0100
+++ extras/gtk2_immodule/gtkimcontextscim.cpp	2013-10-08 18:16:29.000000000 +0200
@@ -1710,7 +1710,7 @@
         // And set manual to false.
         if (!check_socket_frontend ()) {
             std::cerr << "Launching a SCIM daemon with Socket FrontEnd...\n";
-            char *new_argv [] = { static_cast<char*> ("--no-stay"), 0 };
+            char *new_argv [] = { const_cast<char*> ("--no-stay"), 0 };
             scim_launch (true,
                          config_module_name,
                          (load_engine_list.size () ? scim_combine_string_list (load_engine_list, ',') : "all"),
