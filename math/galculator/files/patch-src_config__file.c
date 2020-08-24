--- src/config_file.c.orig	2015-09-05 19:24:27 UTC
+++ src/config_file.c
@@ -39,7 +39,6 @@
 #include "config_file.h"
 #include "general_functions.h"
 
-s_preferences prefs;
 static s_prefs_entry prefs_list[53] = {
 	{"display_bkg_color", &(prefs.bkg_color), STRING, "prefs_bkg_color_button", set_button_color},
 	{"display_result_font", &(prefs.result_font), STRING, "prefs_result_font", set_button_font},
