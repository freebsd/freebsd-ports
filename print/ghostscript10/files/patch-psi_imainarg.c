--- psi/imainarg.c.orig	2023-03-21 14:58:42 UTC
+++ psi/imainarg.c
@@ -109,7 +109,6 @@ static void print_usage(const gs_main_instance *);
 static void print_devices(const gs_main_instance *);
 static void print_emulators(const gs_main_instance *);
 static void print_paths(gs_main_instance *);
-static void print_help_trailer(const gs_main_instance *);
 
 /* ------ Main program ------ */
 
@@ -1262,7 +1261,6 @@ static const char help_debug[] = "\
  --debug                       list debugging options\n";
 #endif
 static const char help_trailer[] = "\
-For more information, see %s.\n\
 Please report bugs to bugs.ghostscript.com.\n";
 static const char help_devices[] = "Available devices:";
 static const char help_default_device[] = "Default output device:";
@@ -1305,7 +1303,7 @@ print_help(gs_main_instance * minst)
     if (have_rom_device) {
         outprintf(minst->heap, "Initialization files are compiled into the executable.\n");
     }
-    print_help_trailer(minst);
+    outprintf(minst->heap, "%s", help_trailer);
 }
 
 /* Print the revision, revision date, and copyright. */
@@ -1450,16 +1448,3 @@ print_paths(gs_main_instance * minst)
     outprintf(minst->heap, "%s", help_fontconfig);
 }
 
-/* Print the help trailer. */
-static void
-print_help_trailer(const gs_main_instance *minst)
-{
-    char buffer[gp_file_name_sizeof];
-    const char *use_htm = "Use.htm", *p = buffer;
-    uint blen = sizeof(buffer);
-
-    if (gp_file_name_combine(gs_doc_directory, strlen(gs_doc_directory),
-            use_htm, strlen(use_htm), false, buffer, &blen) != gp_combine_success)
-        p = use_htm;
-    outprintf(minst->heap, help_trailer, p);
-}
